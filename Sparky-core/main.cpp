#include <iostream>
#include "src\graphics\window.h"
#include <GLFW/glfw3.h>

int main()
{
	using namespace sparky;
	using namespace graphics;

	Window window("Sparky", 1200, 675);

	

	while (!window.closed())
	{
		window.clear();
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
		window.update();
	}



	return 0;
}