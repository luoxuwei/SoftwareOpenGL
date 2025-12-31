//Copyright luoxuwei All Rights Reserved.
#include "../common/base.h"

//传入离散的图元点，返回光栅化后的像素数组


void rasterizeLine(
	std::vector<Point>& results,
	const Point& v0,
	const Point& v1
);

void interpolantLine(const Point& v0, const Point& v1, Point& target);

void rasterizeTriangle(
	std::vector<Point>& results,
	const Point& v0,
	const Point& v1,
	const Point& v2
);

void interpolantTriangle(const Point& v0, const Point& v1, const Point& v2, Point& p);

RGBA lerpRGBA(const RGBA& c0, const RGBA& c1, float weight);

RGBA lerpRGBA(const RGBA& c0, const RGBA& c1, const RGBA& c2, float weight0, float weight1, float weight2);

math::vec2f lerpUV(const math::vec2f& uv0, const math::vec2f& uv1, const math::vec2f& uv2, float weight0, float weight1, float weight2);
math::vec2f lerpUV(const math::vec2f& uv0, const math::vec2f& uv1, float weight);
