//Copyright luoxuwei All Rights Reserved.
#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <assert.h>

#define PI					3.14159265358979323
#define DEG2RAD(theta)		(0.01745329251994329 * (theta))
#define FRACTION(v)			((v) - (int)(v))

using byte = unsigned char;//byte是别名

//注意排布顺序是B-G-R-A(在windows窗体里面的特例)
struct RGBA {
	byte mB;
	byte mG;
	byte mR;
	byte mA;

	RGBA(
		byte r = 255,
		byte g = 255,
		byte b = 255,
		byte a = 255)
	{
		mR = r;
		mG = g;
		mB = b;
		mA = a;
	}
};

struct Point {
	int32_t x;
	int32_t y;
	RGBA color;
};