//Copyright luoxuwei All Rights Reserved.
#include <Windows.h>
#include <iostream>
#include "app/app.h"
#include "opengl/gl.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

void render() {
	glClear();

	//for (uint32_t i = 0; i < app->getWidth(); ++i) {
	//	sgl->drawPoint(i, 500, RGBA(255, 255, 255));
	//}

	for (uint32_t i = 0; i < app->getWidth(); ++i) {
		for (uint32_t j = 0; j < app->getHeight(); ++j) {
			uint32_t v = std::rand() % 255;
			RGBA color(v, v, v, v);
			glDrawPoint(i, j, color);
		}
	}
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
	if (!app->initApplication(hInstance, 800, 600)) {
		return -1;
	}

	glViewport(app->getWidth(), app->getHeight(), app->getCanvas());

	bool alive = true;
	while (alive) {
		alive = app->peekMessage();
		render();
		app->show();
	}

	return 0;
}
