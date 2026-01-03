//Copyright luoxuwei All Rights Reserved.
#include <Windows.h>
#include <iostream>
#include "app/app.h"
#include "opengl/gl.h"
#include "app/image.h"
#include "math/math.h"
#include "opengl/shader/defaultShader.h"
#include "app/model.h"
#include "opengl/shader/lightShader.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

uint32_t WIDTH = 1200;
uint32_t HEIGHT = 900;

Camera* camera = nullptr;

//使用的Shader
LightShader* shader = nullptr;
DirectionalLight directionalLight;
math::vec3f envLight;

//使用的模型
Model* model = nullptr;

float angle = 0;
void transform() {
	angle -= 0.02f;
	auto rotateMatrix = math::rotate(math::mat4f(), angle, {0.0f,1.0f,0.0f});
	auto translateMatrix = math::translate(math::mat4f(), 0.0f, 0.0f, -5.0f);
	auto m = translateMatrix * rotateMatrix;

	m = math::scale(m, 0.1f, 0.1f, 0.1f);
	model->setModelMatrix(m);
}

void prepare() {
	camera = new Camera(60.0f, (float)WIDTH / (float)HEIGHT, 0.1f, 1000.0f, { 0.0f, 1.0f, 0.0f });
	APP->setCamera(camera);

	shader = new LightShader();
	directionalLight.color = {1.0f, 1.0f, 1.0f};
	directionalLight.direction = {-1.0f, -0.5f, -0.7f};
	envLight = { 0.5f, 0.5f, 0.5f };

	glEnable(CULL_FACE);

	model = new Model();
	model->read("assets/model/dinosaur/source/Rampaging T-Rex.glb");
}

void render() {
	transform();

	shader->mViewMatrix = camera->getViewMatrix();
	shader->mProjectionMatrix = camera->getProjectionMatrix();

	shader->mDirectionalLight = directionalLight;
	shader->mEnvLight = envLight;

	glClear();
	glUseProgram(shader);
    model->draw(shader);
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
	if (!APP->init(hInstance, WIDTH, HEIGHT)) {
		return -1;
	}

	glViewport(APP->getWidth(), APP->getHeight(), APP->getCanvas());

	prepare();

	bool alive = true;
	while (alive) {
		alive = APP->peekMessage();
		camera->update();

		render();
		APP->show();
	}

	delete shader;
    delete camera;
	return 0;
}
