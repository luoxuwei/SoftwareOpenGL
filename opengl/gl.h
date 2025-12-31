//Copyright luoxuwei All Rights Reserved.
#pragma once
#include "../common/base.h"
#include "../app/image.h"

void glViewport(const uint32_t& width, const uint32_t& height, void* buffer = nullptr);
void glClear();
void glDrawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color);
void glDrawLine(const Point& p1, const Point& p2);
void glDrawTriangle(const Point& p1, const Point& p2, const Point& p3);
void glDrawImage(const Image* image);

void glDrawImageWidthAlpha(const Image* image, const uint32_t& alpha);

//设置状态
void glSetBlending(bool enable);
void glSetTexture(Image* image);