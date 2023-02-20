#pragma once
#include "cocos2d.h"

cocos2d::Color4B& operator+=(cocos2d::Color4B& lhs, const cocos2d::Color4B& rhs);
cocos2d::Color4B operator+(cocos2d::Color4B lhs, const cocos2d::Color4B& rhs);
cocos2d::Color4B& operator+=(cocos2d::Color4B& lhs, uint8_t rhs);
cocos2d::Color4B operator+(cocos2d::Color4B lhs, uint8_t rhs);

cocos2d::Color4B& operator-=(cocos2d::Color4B& lhs, const cocos2d::Color4B& rhs);
cocos2d::Color4B operator-(cocos2d::Color4B lhs, const cocos2d::Color4B& rhs);
cocos2d::Color4B& operator-=(cocos2d::Color4B& lhs, uint8_t rhs);
cocos2d::Color4B operator-(cocos2d::Color4B lhs, uint8_t rhs);

cocos2d::Color4B& operator*=(cocos2d::Color4B& lhs, const cocos2d::Color4B& rhs);
cocos2d::Color4B operator*(cocos2d::Color4B lhs, const cocos2d::Color4B& rhs);
cocos2d::Color4B& operator*=(cocos2d::Color4B& lhs, float rhs);
cocos2d::Color4B operator*(cocos2d::Color4B lhs, float rhs);

cocos2d::Color4B& operator/=(cocos2d::Color4B& lhs, const cocos2d::Color4B& rhs);
cocos2d::Color4B operator/(cocos2d::Color4B lhs, const cocos2d::Color4B& rhs);
cocos2d::Color4B& operator/=(cocos2d::Color4B& lhs, float rhs);
cocos2d::Color4B operator/(cocos2d::Color4B lhs, float rhs);
