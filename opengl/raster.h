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
