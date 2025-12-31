//Copyright luoxuwei All Rights Reserved.
#pragma once
#include "../common/base.h"
#include "../app/image.h"
#include "render.h"

inline void glViewport(const uint32_t& width, const uint32_t& height, void* buffer) {
	gl->initSurface(width, height, buffer);
}

inline void glClear() {
	gl->clear();
}

inline void glDrawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color) {
	gl->drawPoint(x, y, color);
}

inline void glDrawLine(const Point& p1, const Point& p2) {
	gl->drawLine(p1, p2);
}

inline void glDrawTriangle(const Point& p1, const Point& p2, const Point& p3) {
	gl->drawTriangle(p1, p2, p3);
}

inline void glDrawImage(const Image* image) {
	gl->drawImage(image);
}

inline void glDrawImageWidthAlpha(const Image* image, const uint32_t& alpha) {
	gl->drawImageWidthAlpha(image, alpha);
}

//设置状态
inline void glSetBlending(bool enable) {
	gl->setBlending(enable);
}

inline void glSetTexture(Image* image) {
	gl->setTexture(image);
}

inline void glSetBilinear(bool enable) {
	gl->setBilinear(enable);
}

inline void glSetTextureWrap(uint32_t wrap) {
	gl->setTextureWrap(wrap);
}