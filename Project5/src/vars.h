#ifndef VARS_H
#define VARS_H
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>


namespace GuiVars
{
	struct Settings
	{
		const unsigned int SCR_WIDTH = 800;
		const unsigned int SCR_HEIGHT = 600;
		glm::vec3 view3 = glm::vec3(0.0f);
		glm::vec4 color4 = glm::vec4(0.0f);

		float rotate = 0.0f;
		float cubeRotateSpeed;

		bool isTimeRotate = false;

	};
}



#endif