//Copyright luoxuwei All Rights Reserved.
#pragma once
#include "../common/base.h"

/*
* class FrameBuffer：
* 存储当前画布对应的bmp的内存指针，作为当前绘图画板
*/
class FrameBuffer {
public:
	FrameBuffer(uint32_t width, uint32_t height, void* buffer = nullptr);
	~FrameBuffer();
	FrameBuffer(const FrameBuffer&) = delete;//不准拷贝复制

	uint32_t	mWidth{ 0 };
	uint32_t	mHeight{ 0 };
	RGBA* mColorBuffer{ nullptr }; //这个就是由Application传进来的mCanvasBuffer
	bool		mExternBuffer{ false }; //是否是外界传进来的 如果不是 则自己要产生一个画板内存
};