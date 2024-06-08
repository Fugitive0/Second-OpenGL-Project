#ifndef VBO_H
#define VBO_H


class VertexBufferObject
{
public: // Variables
	unsigned int m_ID;

public: // Methods 
	VertexBufferObject(unsigned int VAO, size_t verticeSize, float vertices[]);
	~VertexBufferObject();
	unsigned int GetBuffer() const;
	void Bind() const;
	void UnBind() const;





};











#endif // !VBO_H
