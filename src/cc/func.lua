--

function CC_SAFE_RETAIN(ref)
    if ref then
        ref:retain()
    end
end

function CC_SAFE_RELEASE(ref)
    if ref then
        ref:release()
    end
end

function CC_SAFE_REMOVE(node)
    if node then
        node:removeSelf()
    end
end

function CC_SET_PROP_CHILDREN(parent, key, node)
    if node == parent[key] then
        return
    end
    if parent[key] then
        parent[key]:removeSelf()
    end
    parent[key] = node
    if parent[key] then
        parent[key]:addTo(parent)
    end
end

