#include <iostream>
#include "src/graphics/Window.h"
#include "src/maths/maths.h"

int main()
{
	//If you see this, then you're a real nigger
	using namespace engineCore;
	using namespace graphics;
	Window window("Fidelio",800,600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	double x, y;
	while (!window.closed())
	{
		window.clear();
		if (window.isButtonPressed(GLFW_MOUSE_BUTTON_1))
		{
			std::cout << "LEFT dun pressed" << std::endl;
		}
		window.getMousePosition(x, y);
		std::cout << "X: " << x << "Y: " << y << std::endl;
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.update();
	}
	return 0;
}
