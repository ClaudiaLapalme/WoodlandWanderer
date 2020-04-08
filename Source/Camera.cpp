#include "../Include/Camera.h"


Camera::Camera() {
	this->cameraPosition = glm::vec3(0.0f, 9.5f, -4.0f);
	this->cameraLookAt = glm::vec3(0.0f, 0.0f, 1.0f);
	this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
}

Camera::Camera(glm::vec3 _cameraPosition, glm::vec3 _cameraLookAt, glm::vec3 _cameraUp)
	:cameraPosition(_cameraPosition), cameraLookAt(_cameraLookAt), cameraUp(_cameraUp)
{}