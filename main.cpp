//Copyright luoxuwei All Rights Reserved.
#include <Windows.h>
#include <iostream>
#include "app/app.h"
#include "opengl/gl.h"
#include "app/image.h"
#include "math/math.h"
#include "opengl/shader/defaultShader.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

uint32_t WIDTH = 800;
uint32_t HEIGHT = 600;

//两个三角形，三个属性对应vbo
uint32_t positionVbo0 = 0;
uint32_t positionVbo1 = 0;
uint32_t colorVbo0 = 0;
uint32_t colorVbo1 = 0;

uint32_t uvVbo = 0;

//三角形的indices
uint32_t ebo = 0;

//两个三角形专属vao
uint32_t vao0 = 0;
uint32_t vao1 = 0;

//使用的Shader
DefaultShader* shader = nullptr;

//mvp变换矩阵
math::mat4f modelMatrix;
math::mat4f viewMatrix;
math::mat4f perspectiveMatrix;


float angle = 0.0f;
float cameraZ = 2.0f;
void transform() {
	//angle += 0.01f;
	//cameraZ -= 0.01f;

	//模型变换
	modelMatrix = math::rotate(math::mat4f(1.0f), angle, math::vec3f{ 0.0f, 1.0f, 0.0f });

	//视图变换
	auto cameraModelMatrix = math::translate(math::mat4f(1.0f), math::vec3f{ 0.0f, 0.0f, cameraZ });
	viewMatrix = math::inverse(cameraModelMatrix);
}

void prepare() {
	shader = new DefaultShader();

	perspectiveMatrix = math::perspective(60.0f, (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

	auto cameraModelMatrix = math::translate(math::mat4f(1.0f), math::vec3f{ 0.0f, 0.0f, cameraZ });
	viewMatrix = math::inverse(cameraModelMatrix);

	glEnable(CULL_FACE);
	glFrontFace(FRONT_FACE_CCW);
	glCullFace(BACK_FACE);

	//glDisable(DEPTH_TEST);

	//第一个三角形
	float positions0[] = {
		-0.5f, 0.0f, 0.0f,
		0.5f, 0.0f, 0.0f,
		0.25f, 0.5f, 0.0f,
	};

	float colors0[] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
	};

	//第二个三角形
	float positions1[] = {
		0.3f, 0.0f, -0.3f,
		0.8f, 0.0f, -0.3f,
		0.45f, 0.5f, -0.3f,
	};

	float colors1[] = {
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
	};

	float uvs[] = {
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
	};

	uint32_t indices[] = { 0, 1, 2 };

	//生成indices对应ebo, 二者公用
	ebo = glGenBuffer();
	glBindBuffer(ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * 3, indices);
	glBindBuffer(ELEMENT_ARRAY_BUFFER, 0);

	//生成uv对应的vbo，二者公用
	uvVbo = glGenBuffer();
	glBindBuffer(ARRAY_BUFFER, uvVbo);
	glBufferData(ARRAY_BUFFER, sizeof(float) * 6, uvs);
	glBindBuffer(ARRAY_BUFFER, 0);

	//生成vao并且绑定
	vao0 = glGenVertexArray();
	glBindVertexArray(vao0);

	//position0
	positionVbo0 = glGenBuffer();
	glBindBuffer(ARRAY_BUFFER, positionVbo0);
	glBufferData(ARRAY_BUFFER, sizeof(float) * 9, positions0);
	glVertexAttributePointer(0, 3, 3 * sizeof(float), 0);

	//color0
	colorVbo0 = glGenBuffer();
	glBindBuffer(ARRAY_BUFFER, colorVbo0);
	glBufferData(ARRAY_BUFFER, sizeof(float) * 12, colors0);
	glVertexAttributePointer(1, 4, 4 * sizeof(float), 0);

	//uv
	glBindBuffer(ARRAY_BUFFER, uvVbo);
	glVertexAttributePointer(2, 2, 2 * sizeof(float), 0);

	glBindBuffer(ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//生成vao并且绑定
	vao1 = glGenVertexArray();
	glBindVertexArray(vao1);

	//position1
	positionVbo1 = glGenBuffer();
	glBindBuffer(ARRAY_BUFFER, positionVbo1);
	glBufferData(ARRAY_BUFFER, sizeof(float) * 9, positions1);
	glVertexAttributePointer(0, 3, 3 * sizeof(float), 0);

	//color1
	colorVbo1 = glGenBuffer();
	glBindBuffer(ARRAY_BUFFER, colorVbo1);
	glBufferData(ARRAY_BUFFER, sizeof(float) * 12, colors1);
	glVertexAttributePointer(1, 4, 4 * sizeof(float), 0);

	//uv
	glBindBuffer(ARRAY_BUFFER, uvVbo);
	glVertexAttributePointer(2, 2, 2 * sizeof(float), 0);

	glBindBuffer(ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void render() {
	transform();
	shader->mModelMatrix = modelMatrix;
	shader->mViewMatrix = viewMatrix;
	shader->mProjectionMatrix = perspectiveMatrix;

	glClear();
	glUseProgram(shader);
	glBindVertexArray(vao0);
	glBindBuffer(ELEMENT_ARRAY_BUFFER, ebo);
	glDrawElement(DRAW_TRIANGLES, 0, 3);

	glBindVertexArray(vao1);
	glBindBuffer(ELEMENT_ARRAY_BUFFER, ebo);
	glDrawElement(DRAW_TRIANGLES, 0, 3);
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
	if (!app->init(hInstance, WIDTH, HEIGHT)) {
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

	delete shader;

	return 0;
}
