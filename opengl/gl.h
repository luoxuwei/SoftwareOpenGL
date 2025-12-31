//Copyright luoxuwei All Rights Reserved.
#pragma once
#include "../common/base.h"

void glViewport(const uint32_t& width, const uint32_t& height, void* buffer = nullptr);
void glClear();
void glDrawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color);
void glDrawLine(const Point& p1, const Point& p2);