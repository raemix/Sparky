#include <GLFW/glfw3.h>
#include <iostream>
#include "src\graphics\window.h"

int main()
{
	using namespace sparky;
	using namespace graphics;

	Window window("Sparky", 1200, 675);


	while (!window.closed())
	{
		std::cout << window.getWidth() << "x" << window.getHeight() << std::endl;
		window.clear();
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);

		glEnd();
		window.update();
	}



	return 0;
}