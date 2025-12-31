//Copyright luoxuwei All Rights Reserved.
#pragma once
#include "../common/base.h"
#include "frameBuffer.h"
#include "../app/app.h"
#include "../app/image.h"
#include "../math/math.h"
#include "data.h"
#include "vao.h"
#include "vbo.h"

#define gl Render::getInstance()

/*
* class Render：
* 绘图行为以及算法
*/
class Render {
public:
	static Render* getInstance();
	Render();

	~Render();

	//接受外界传入的bmp对应的内存指针以及窗体的宽/高
	void initSurface(const uint32_t& width, const uint32_t& height, void* buffer = nullptr);

	//清除画布内容
	void clear();

	uint32_t genBuffer();
	void deleteBuffer(const uint32_t& bufferID);

	uint32_t genVertexArray();
	void deleteVertexArray(const uint32_t& vaoID);

private:
	static Render* mInstance;

	FrameBuffer* mFrameBuffer{ nullptr };

	//VBO相关/EBO也存在内部
	uint32_t mBufferCounter{ 0 };
	std::map<uint32_t, BufferObject*> mBufferMap;

	//VAO相关
	uint32_t mVaoCounter{ 0 };
	std::map<uint32_t, VertexArrayObject*> mVaoMap;
};