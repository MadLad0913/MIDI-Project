#include <iostream>
#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Window Dimensions 
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    //Initialize GLFW
	if (!glfwInit())
	{
		std::cout << ("GLFW initialization failed!");
		glfwTerminate();
		return 1;
	}

	//SETUP GLFW WINDOW PROPERTIES
	//OPENGL VERSION
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//CORE PROFILE = NO BACKWARDS COMPATIBILITY 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//ALLOW FORWARD COMPATIBILITY 
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* mainwindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	if (!mainwindow) {
		std::cout << "GLFW window creation failed";
		glfwTerminate();
		return 1;
	}

	//GET BUFFER SIZE INFORAMTION
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainwindow, &bufferWidth, &bufferHeight);

	//SET CONTEXT FOR GLEW TO USE
	glfwMakeContextCurrent(mainwindow);

	//ALLOW MODERN EXTENSION FEATURES
	glewExperimental = GL_TRUE;
	
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW intitialization failed!";
		glfwDestroyWindow(mainwindow);
		glfwTerminate();
		return 1;
	}

	//SETUP VIEWPORT SIZE
	glViewport(0, 0, bufferWidth, bufferHeight);

	//LOOP UNTIL WINDOW CLOSED
	while (glfwWindowShouldClose(mainwindow))
		//GET AND HANDLE USER INPUT EVENTS
		glfwPollEvents();

		//CLEAR WINDOW
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainwindow);
}
