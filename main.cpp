//Copyright luoxuwei All Rights Reserved.
#include <Windows.h>
#include <iostream>
#include "app/app.h"
#include "opengl/gl.h"
#include "app/image.h"
#include "math/math.h"
#include "opengl/shader/defaultShader.h"
#include "opengl/shader/textureShader.h"

#pragma comment(linker, "/subsystem:console /entry:wWinMainCRTStartup" )

uint32_t WIDTH = 800;
uint32_t HEIGHT = 600;

Camera* camera = nullptr;

//两个三角形，三个属性对应vbo
uint32_t positionVbo = 0;

uint32_t colorVbo = 0;

uint32_t uvVbo = 0;

//三角形的indices
uint32_t ebo = 0;

//两个三角形专属vao
uint32_t vao = 0;

//使用的Shader
TextureShader* shader = nullptr;

//使用的texture
uint32_t texture = 0;
Image* image = nullptr;

//mvp变换矩阵
math::mat4f modelMatrix;

void prepare() {
	camera = new Camera(60.0f, (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f, {0.0f, 1.0f, 0.0f});
	app->setCamera(camera);

	shader = new TextureShader();

	//制造纹理
	image = Image::createImage("assets/textures/goku.jpg");
	texture = glGenTexture();
	glBindTexture(texture);
	glTexImage2D(image->mWidth, image->mHeight, image->mData);
	glTexParameter(TEXTURE_FILTER, TEXTURE_FILTER_LINEAR);
	glTexParameter(TEXTURE_WRAP_U, TEXTURE_WRAP_REPEAT);
	glTexParameter(TEXTURE_WRAP_V, TEXTURE_WRAP_REPEAT);
	glBindTexture(0);

	glEnable(CULL_FACE);
	glFrontFace(FRONT_FACE_CCW);
	glCullFace(BACK_FACE);

	float positions[] = {
		-0.5f, 0.0f, -1.0f,
		0.5f, 0.0f, -1.0f,
		0.0f, 0.5f, -1.0f,
	};

	float colors[] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
	};

	float uvs[] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		0.5f, 1.0f,
	};

	uint32_t indices[] = { 0, 1, 2 };

	//生成indices对应ebo
	ebo = glGenBuffer();
	glBindBuffer(ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * 3, indices);
	glBindBuffer(ELEMENT_ARRAY_BUFFER, 0);

	//生成vao并且绑定
	vao = glGenVertexArray();
	glBindVertexArray(vao);

	//position
	positionVbo = glGenBuffer();
	glBindBuffer(ARRAY_BUFFER, positionVbo);
	glBufferData(ARRAY_BUFFER, sizeof(float) * 9, positions);
	glVertexAttributePointer(0, 3, 3 * sizeof(float), 0);

	//color
	colorVbo = glGenBuffer();
	glBindBuffer(ARRAY_BUFFER, colorVbo);
	glBufferData(ARRAY_BUFFER, sizeof(float) * 12, colors);
	glVertexAttributePointer(1, 4, 4 * sizeof(float), 0);

	//uv
	uvVbo = glGenBuffer();
	glBindBuffer(ARRAY_BUFFER, uvVbo);
	glBufferData(ARRAY_BUFFER, sizeof(float) * 6, uvs);
	glVertexAttributePointer(2, 2, 2 * sizeof(float), 0);

	glBindBuffer(ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void render() {
	shader->mModelMatrix = modelMatrix;
	shader->mViewMatrix = camera->getViewMatrix();
	shader->mProjectionMatrix = camera->getProjectionMatrix();
	shader->mDiffuseTexture = texture;

	glClear();
	glUseProgram(shader);

	glBindVertexArray(vao);
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
		camera->update();

		render();
		app->show();
	}

	delete shader;
	Image::destroyImage(image);
	glDeleteTexture(texture);
	return 0;
}
