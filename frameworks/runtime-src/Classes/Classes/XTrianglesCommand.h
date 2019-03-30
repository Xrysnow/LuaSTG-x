#pragma once
#include "renderer/CCTrianglesCommand.h"
#include "2d/CCAutoPolygon.h"

class XTrianglesCommand : public cocos2d::TrianglesCommand
{
public:
	void init(float globalOrder, GLuint textureID, cocos2d::GLProgramState* glProgramState,
		cocos2d::BlendFunc blendType, GLuint blendEquation, const Triangles& triangles, const cocos2d::Mat4& mv);
	void init(float globalOrder, cocos2d::Texture2D* texture, cocos2d::GLProgramState* glProgramState,
		cocos2d::BlendFunc blendType, GLuint blendEquation, const Triangles& triangles, const cocos2d::Mat4& mv);
	void init(float globalOrder, cocos2d::Texture2D* texture, cocos2d::GLProgramState* glProgramState,
		cocos2d::BlendFunc blendType, GLuint blendEquation);

	void generateMaterialID() override;
	void useMaterial() const override;

	//TODO: setExternalMV
	cocos2d::Mat4* getMV() { return &_mv; }
	Triangles* getTri() { return &_triangles; }

	void copyProperties(XTrianglesCommand* other) const;

	XTrianglesCommand();
	~XTrianglesCommand();

	static Triangles mergeTiangles(Triangles* trangles, uint32_t count);
	static Triangles mergeTiangles(Triangles trangles, cocos2d::Mat4* mats, uint32_t count);
	static Triangles mergeTiangles(Triangles* trangles, cocos2d::Mat4* mats, uint32_t count);
	static void releaseTiangles(Triangles* trangles);

	static bool isBlendFuncSeparate;
protected:
	void releaseTrangles();
private:
	GLuint _glBlendEquation = GL_FUNC_ADD;
	bool _isBlendFuncSeparate = false;
};
