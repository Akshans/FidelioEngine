#include <GLFW\glfw3.h>
#include <iostream>

#include "src\graphics\Window.h"
int main()
{
	using namespace engineCore;
	using namespace graphics;
	Window window("Fidelio",800,600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;
	while (!window.closed())
	{
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.update();
	}
	return 0;
}