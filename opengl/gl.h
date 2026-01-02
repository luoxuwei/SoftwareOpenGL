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

inline void glUseProgram(Shader *shader) {
	gl->useProgram(shader);
}

inline void glDrawElement(const uint32_t& drawMode, const uint32_t& first, const uint32_t& count) {
	gl->drawElement(drawMode, first, count);
}

inline void glEnable(const uint32_t& value) {
	gl->enable(value);;
}

inline void glDisable(const uint32_t& value) {
	gl->disable(value);;
}

inline void glFrontFace(const uint32_t& value) {
	gl->frontFace(value);
}
inline void glCullFace(const uint32_t& value) {
	gl->cullFace(value);
}

inline uint32_t glGenTexture() {
	return gl->genTexture();
}

inline void glBindTexture(const uint32_t& texID) {
	gl->bindTexture(texID);
}

inline void glTexImage2D(const uint32_t& width, const uint32_t& height, void* data) {
	gl->texImage2D(width, height, data);
}

inline void glTexParameter(const uint32_t& param, const uint32_t& value) {
	gl->texParameter(param, value);
}

inline void glDeleteTexture(const uint32_t& texID) {
	gl->deleteTexture(texID);
}

inline void printVAO(const uint32_t& vaoID) {
	gl->printVAO(vaoID);
}
