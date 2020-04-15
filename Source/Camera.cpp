#include "../Include/Camera.h"

Camera::Camera() {
	this->cameraPosition = glm::vec3(0.0f, 9.5f, -0.1f);
	this->cameraLookAt = glm::vec3(0.0f, 0.0f, 1.0f);
	this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
}

Camera::Camera(glm::vec3 _cameraPosition, glm::vec3 _cameraLookAt, glm::vec3 _cameraUp)
	:cameraPosition(_cameraPosition), cameraLookAt(_cameraLookAt), cameraUp(_cameraUp)
{}

void Camera::onRender(GLFWwindow* window) {
	float cameraSpeed;

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS
		|| glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS) {
		cameraSpeed = 2.5;
	}
	else {
		cameraSpeed = 0.5;
	}

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		cameraPosition += cameraSpeed * cameraLookAt;
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		cameraPosition -= cameraSpeed * cameraLookAt;
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		cameraPosition -= glm::normalize(glm::cross(cameraLookAt, cameraUp)) * cameraSpeed;
	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		cameraPosition += glm::normalize(glm::cross(cameraLookAt, cameraUp)) * cameraSpeed;
	}

}

void Camera::setCameraVariables(GLFWwindow* window,
	double& mousePosX,
	double& mousePosY,
	double& lastMousePosX,
	double& lastMousePosY,
	float& camHorAngle,
	float& camVertAngle) {

	glfwGetCursorPos(window, &mousePosX, &mousePosY);

	dx = mousePosX - lastMousePosX;
	dy = mousePosY - lastMousePosY;

	lastMousePosX = mousePosX;
	lastMousePosY = mousePosY;

	theta = glm::radians(cameraHorizontalAngle);
	phi = glm::radians(cameraVerticalAngle);

	// Clamp vertical angle to [-85, 85] degrees
	camVertAngle = glm::max(-85.0f, glm::min(85.0f, camVertAngle));

	// Allow camera to rotate about horizontally
	if (camHorAngle > 360) {
		camHorAngle -= 360;
	}
	else if (camHorAngle < -360) {
		camHorAngle += 360;
	}

	cameraLookAt = glm::vec3(cosf(phi) * cosf(theta), sinf(phi), -cosf(phi) * sinf(theta));
	cameraSideVector = cross(cameraLookAt, glm::vec3(0.0f, 1.0f, 0.0f));
	normalize(cameraSideVector);
}
