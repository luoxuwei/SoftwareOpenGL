//Copyright luoxuwei All Rights Reserved.
#include "../math/math.h"
#include "data.h"

//传入离散的图元点，返回光栅化后的像素数组
void rasterize(
	std::vector<VsOutput>& results,
	const uint32_t& drawMode,
	const std::vector<VsOutput>& inputs
);

void rasterizeLine(
	std::vector<VsOutput>& results,
	const VsOutput& v0,
	const VsOutput& v1);

void interpolantLine(const VsOutput& v0, const VsOutput& v1, VsOutput& target);

void rasterizeTriangle(
	std::vector<VsOutput>& results,
	const VsOutput& v0,
	const VsOutput& v1,
	const VsOutput& v2);

void interpolantTriangle(const VsOutput& v0, const VsOutput& v1, const VsOutput& v2, VsOutput& p);


