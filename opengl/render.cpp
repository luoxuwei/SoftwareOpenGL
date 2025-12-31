//Copyright luoxuwei All Rights Reserved.
#include "render.h"
#include "gl.h"
#include "raster.h"

Render* Render::mInstance = nullptr;
Render* Render::getInstance() {
	if (!mInstance) {
		mInstance = new Render();
	}

	return mInstance;
}

Render::Render() {}

Render::~Render() {
	if (mFrameBuffer) {
		delete mFrameBuffer;
	}
}

void Render::initSurface(const uint32_t& width, const uint32_t& height, void* buffer) {
	mFrameBuffer = new FrameBuffer(width, height, buffer);
}

void Render::clear() {
	size_t pixelSize = mFrameBuffer->mWidth * mFrameBuffer->mHeight; // 总共的像素数
	std::fill_n(mFrameBuffer->mColorBuffer, pixelSize, RGBA(0, 0, 0, 0));
}

void Render::drawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color) {
	//从窗口左下角开始算起
	uint32_t pixelPos = y * mFrameBuffer->mWidth + x; // 在最后一行加上x的偏移量
	mFrameBuffer->mColorBuffer[pixelPos] = color;
}

void Render::drawLine(const Point& p1, const Point& p2) {
	std::vector<Point> pixels;
	rasterizeLine(pixels, p1, p2);

	for (auto p : pixels) {
		drawPoint(p.x, p.y, p.color);
	}
}


//
void glViewport(const uint32_t& width, const uint32_t& height, void* buffer) {
	gl->initSurface(width, height, buffer);
}

void glClear() {
	gl->clear();
}

void glDrawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color) {
	gl->drawPoint(x, y, color);
}

void glDrawLine(const Point& p1, const Point& p2) {
	gl->drawLine(p1, p2);
}