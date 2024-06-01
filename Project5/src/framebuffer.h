#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H


#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>

class FrameBuffer
{
public:
	FrameBuffer(float width, float height);
	~FrameBuffer();
	unsigned int getFrameTexture();
	void rescaleFrameBuffer(float width, float height);
	void bind();
	void unBind();

private:
	unsigned int fbo;
	unsigned int texture;
	unsigned int rbo;
};











#endif // !
