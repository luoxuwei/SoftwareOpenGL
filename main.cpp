//Copyright luoxuwei All Rights Reserved.
#include <Windows.h>
#include <iostream>
#include "app/app.h"
#include "opengl/gl.h"
#include "app/image.h"
#include "math/math.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

Image* texture;
Point p1;
Point p2;
Point p3;
void render() {
	glClear();

	glSetTexture(texture);
	glDrawTriangle(p1, p2, p3);
}


void prepare() {
	texture = Image::createImage("assets/textures/goku.jpg");

	p1.x = 0;
	p1.y = 0;
	p1.color = RGBA(255, 0, 0, 255);
	p1.uv = math::vec2f(0.0f, 0.0f);

	p2.x = 400;
	p2.y = 900;
	p2.color = RGBA(0, 255, 0, 255);
	p2.uv = math::vec2f(0.5f, 1.0f);

	p3.x = 800;
	p3.y = 0;
	p3.color = RGBA(0, 0, 255, 255);
	p3.uv = math::vec2f(1.0f, 0.0f);
}

/*
* 1 主循环流程在winMain函数中
* 2 窗体构建，消息处理，其他方面的细节都封装在application类里面
*/
int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance,		//本应用程序实例句柄，唯一指代当前程序
	_In_opt_ HINSTANCE hPrevInstance,	//本程序前一个实例，一般是null
	_In_ LPWSTR    lpCmdLine,		//应用程序运行参数
	_In_ int       nCmdShow)		//窗口如何显示（最大化、最小化、隐藏），不需理会
{
	if (!app->init(hInstance, 800, 600)) {
		return -1;
	}

	glViewport(app->getWidth(), app->getHeight(), app->getCanvas());

	prepare();

	bool alive = true;
	while (alive) {
		alive = app->peekMessage();
		render();
		app->show();
	}

	Image::destroyImage(texture);

	return 0;
}
