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

inline uint32_t glGenBuffer() {
	return gl->genBuffer();
}

inline void glDeleteBuffer(uint32_t vbo) {
	gl->deleteBuffer(vbo);
}

inline uint32_t glGenVertexArray() {
	return gl->genVertexArray();
}

inline void glDeleteVertexArray(uint32_t vao) {
	gl->deleteVertexArray(vao);
}