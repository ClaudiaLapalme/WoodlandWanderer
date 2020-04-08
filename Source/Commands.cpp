#include "../Include/Commands.h"

/**
* Checks to see if the user pressed enter.
* If they did, the program exits.
*/
void Commands::closeWindow(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

/**
* Checks to see which rendering mode is selected by the user.
*/
void Commands::setRenderingMode(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	}
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

/**
* Move the camera in the world
*/
void Commands::processCameraDirection(GLFWwindow* window, glm::vec3& cameraPos, glm::vec3& cameraLookAt, glm::vec3& cameraUp, float deltaTime) {
	float cameraSpeed = deltaTime + 0.1;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		cameraPos += cameraSpeed * cameraLookAt;
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		cameraPos -= cameraSpeed * cameraLookAt;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		cameraPos -= glm::normalize(glm::cross(cameraLookAt, cameraUp)) * cameraSpeed;
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		cameraPos += glm::normalize(glm::cross(cameraLookAt, cameraUp)) * cameraSpeed;
	}
}


void Commands::processCameraRoamDirection(GLFWwindow* window, glm::vec3& cameraPos, glm::vec3& cameraLookAt, glm::vec3& cameraUp, float deltaTime) {
	float cameraSpeed = deltaTime + 0.1;

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		cameraPos += cameraSpeed * cameraLookAt;
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		cameraPos -= cameraSpeed * cameraLookAt;
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		cameraPos -= glm::normalize(glm::cross(cameraLookAt, cameraUp)) * cameraSpeed;
	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		cameraPos += glm::normalize(glm::cross(cameraLookAt, cameraUp)) * cameraSpeed;
	}

}
