#pragma once
#include "cocos2d.h"

cc::Color4B& operator+=(cc::Color4B& lhs, const cc::Color4B& rhs);
cc::Color4B operator+(cc::Color4B lhs, const cc::Color4B& rhs);
cc::Color4B& operator+=(cc::Color4B& lhs, uint8_t rhs);
cc::Color4B operator+(cc::Color4B lhs, uint8_t rhs);

cc::Color4B& operator-=(cc::Color4B& lhs, const cc::Color4B& rhs);
cc::Color4B operator-(cc::Color4B lhs, const cc::Color4B& rhs);
cc::Color4B& operator-=(cc::Color4B& lhs, uint8_t rhs);
cc::Color4B operator-(cc::Color4B lhs, uint8_t rhs);

cc::Color4B& operator*=(cc::Color4B& lhs, const cc::Color4B& rhs);
cc::Color4B operator*(cc::Color4B lhs, const cc::Color4B& rhs);
cc::Color4B& operator*=(cc::Color4B& lhs, float rhs);
cc::Color4B operator*(cc::Color4B lhs, float rhs);

cc::Color4B& operator/=(cc::Color4B& lhs, const cc::Color4B& rhs);
cc::Color4B operator/(cc::Color4B lhs, const cc::Color4B& rhs);
cc::Color4B& operator/=(cc::Color4B& lhs, float rhs);
cc::Color4B operator/(cc::Color4B lhs, float rhs);
