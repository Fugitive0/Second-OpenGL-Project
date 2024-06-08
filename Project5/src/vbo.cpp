#include <glad/glad.h>
#include "vbo.h"


VertexBufferObject::VertexBufferObject(unsigned int VAO, size_t verticeSize, float vertices[])
{
	// Create the vertexBuffer and assign it to the m_ID
	glGenBuffers(1, &m_ID);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_ID); // The below code will now affect the VBO
	glBufferData(GL_ARRAY_BUFFER, verticeSize, vertices, GL_STATIC_DRAW); // We give our vertex buffer array data.

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

VertexBufferObject::~VertexBufferObject()
{
	glDeleteBuffers(1, &m_ID);
}

unsigned int VertexBufferObject::GetBuffer() const
{

	// Returns the ID of the VBO

	return m_ID;
}

void VertexBufferObject::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VertexBufferObject::UnBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}