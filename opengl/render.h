//Copyright luoxuwei All Rights Reserved.
#pragma once
#include "../common/base.h"
#include "frameBuffer.h"
#include "../app/app.h"
#include "../app/image.h"

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

	//传入像素位置，绘制成某种颜色
	void drawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color);
	void drawLine(const Point& p1, const Point& p2);
	void drawTriangle(const Point& p1, const Point& p2, const Point& p3);
	void drawImage(const Image* image);

	void drawImageWidthAlpha(const Image* image, const uint32_t& alpha);

	//设置状态
	void setBlending(bool enable);
	void setTexture(Image* image);
private:
	RGBA sampleNearest(const math::vec2f& uv);
private:
	static Render* mInstance;

	FrameBuffer* mFrameBuffer{ nullptr };
	bool mEnableBlending{ false };
	//纹理贴图
	Image* mImage{ nullptr };
};