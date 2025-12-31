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

	for (auto iter : mBufferMap) {
		delete iter.second;
	}
	mBufferMap.clear();

	for (auto iter : mVaoMap) {
		delete iter.second;
	}
	mVaoMap.clear();
}

void Render::initSurface(const uint32_t& width, const uint32_t& height, void* buffer) {
	mFrameBuffer = new FrameBuffer(width, height, buffer);
}

void Render::clear() {
	size_t pixelSize = mFrameBuffer->mWidth * mFrameBuffer->mHeight; // 总共的像素数
	std::fill_n(mFrameBuffer->mColorBuffer, pixelSize, RGBA(0, 0, 0, 0));
}

uint32_t Render::genBuffer() {
	mBufferCounter++;
	mBufferMap.insert(std::make_pair(mBufferCounter, new BufferObject()));

	return mBufferCounter;
}

void Render::deleteBuffer(const uint32_t& bufferID) {
	auto iter = mBufferMap.find(bufferID);
	if (iter != mBufferMap.end()) {
		delete iter->second;
	}
	else {
		return;
	}

	mBufferMap.erase(iter);
}

uint32_t Render::genVertexArray() {
	mVaoCounter++;
	mVaoMap.insert(std::make_pair(mVaoCounter, new VertexArrayObject()));

	return mVaoCounter;
}

void Render::deleteVertexArray(const uint32_t& vaoID) {
	auto iter = mVaoMap.find(vaoID);
	if (iter != mVaoMap.end()) {
		delete iter->second;
	}
	else {
		return;
	}

	mVaoMap.erase(iter);
}