#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {
	// Initialize GLFW.
	glfwInit();

	// Dictate what version we're using: 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell GLFW we only using CORE functions.
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a window 800x800.
	GLFWwindow* window = glfwCreateWindow(800, 800, "LearningOpenGL", NULL, NULL);

	// If the window is NULL somehow, error out.
	if (window == NULL) {
		std::cout << "something is wrong with window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Set this window to the current context.
	glfwMakeContextCurrent(window);

	// Load GLAD.
	gladLoadGL();

	// Specify viewport, the area that OpenGL can render in.
	glViewport(0, 0, 800, 800);

	// Specify a colour for background.
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

	// Clean the back buffer, assign the new colour to it.
	glClear(GL_COLOR_BUFFER_BIT);

	// Swap the back buffer with the front buffer.
	glfwSwapBuffers(window);

	// Main loop.
	while (!glfwWindowShouldClose(window)) {
		// Record GLFW events.
		glfwPollEvents();
	}

	// Delete window before ending process.
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}