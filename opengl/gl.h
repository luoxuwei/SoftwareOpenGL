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

inline void glBindBuffer(const uint32_t& bufferType, const uint32_t& bufferID) {
	gl->bindBuffer(bufferType, bufferID);
}

inline void glBufferData(const uint32_t& bufferType, size_t dataSize, void* data) {
	gl->bufferData(bufferType, dataSize, data);
}

inline void glBindVertexArray(const uint32_t& vaoID) {
	gl->bindVertexArray(vaoID);
}

inline void glVertexAttributePointer(
	const uint32_t& binding,
	const uint32_t& itemSize,
	const uint32_t& stride,
	const uint32_t& offset) {
	gl->vertexAttributePointer(binding, itemSize, stride, offset);
}

inline void printVAO(const uint32_t& vaoID) {
	gl->printVAO(vaoID);
}
