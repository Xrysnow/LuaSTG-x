#pragma once

#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

namespace lstg
{
	using FileBytes = std::shared_ptr<const std::vector<uint8_t>>;

	// Published bytes must remain immutable, including through any mutable aliases
	// kept by a loader. The owner must outlive all calls, including pending loaders.
	class ResourceFileCache
	{
		struct Entry
		{
			FileBytes bytes;
			size_t pending = 0;
		};

		mutable std::mutex mut;
		std::unordered_map<std::string, std::shared_ptr<Entry>> entries;

		FileBytes finishLoad(const std::string& key,
			const std::shared_ptr<Entry>& generation, FileBytes bytes)
		{
			std::lock_guard<std::mutex> lock(mut);
			--generation->pending;
			const auto it = entries.find(key);
			// Entry identity is the generation: remove/clear detach old loaders.
			// Holding that Entry prevents identity reuse while a loader is pending.
			if (it != entries.end() && it->second == generation)
			{
				if (bytes)
				{
					if (generation->bytes)
						return generation->bytes;
					generation->bytes = bytes;
				}
				else if (!generation->bytes && generation->pending == 0)
				{
					entries.erase(it);
				}
			}
			return bytes;
		}

	public:
		FileBytes find(const std::string& key) const
		{
			std::lock_guard<std::mutex> lock(mut);
			const auto it = entries.find(key);
			return it == entries.end() ? nullptr : it->second->bytes;
		}

		// Competing loaders may run concurrently; the first successful publish
		// wins. Invalidated loaders still return their own uncached snapshot.
		// A null result is a failure; a non-null empty vector is a valid file.
		FileBytes load(const std::string& key, const std::function<FileBytes()>& loader)
		{
			std::shared_ptr<Entry> generation;
			{
				std::lock_guard<std::mutex> lock(mut);
				const auto it = entries.find(key);
				if (it != entries.end())
				{
					if (it->second->bytes)
						return it->second->bytes;
					generation = it->second;
				}
				else
				{
					generation = std::make_shared<Entry>();
					entries.emplace(key, generation);
				}
				++generation->pending;
			}
			FileBytes bytes;
			try
			{
				bytes = loader();
			}
			catch (...)
			{
				finishLoad(key, generation, nullptr);
				throw;
			}
			return finishLoad(key, generation, bytes);
		}

		bool contains(const std::string& key) const
		{
			return !!find(key);
		}

		// Also invalidates pending loaders when no completed file is cached.
		// The result reports whether a completed cached file was removed.
		bool remove(const std::string& key)
		{
			std::lock_guard<std::mutex> lock(mut);
			const auto it = entries.find(key);
			if (it == entries.end())
				return false;
			const bool hadBytes = !!it->second->bytes;
			entries.erase(it);
			return hadBytes;
		}

		void clear()
		{
			std::lock_guard<std::mutex> lock(mut);
			entries.clear();
		}

		size_t size() const
		{
			std::lock_guard<std::mutex> lock(mut);
			size_t total = 0;
			for (const auto& entry : entries)
				if (entry.second->bytes)
					total += entry.second->bytes->size();
			return total;
		}

		std::vector<std::string> list() const
		{
			std::lock_guard<std::mutex> lock(mut);
			std::vector<std::string> result;
			for (const auto& entry : entries)
				if (entry.second->bytes)
					result.push_back(entry.first);
			return result;
		}
	};
}
