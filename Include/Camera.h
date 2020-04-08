#pragma once
#include <GL/glew.h>    // Include GLEW - OpenGL Extension Wrangler
#include <GLFW/glfw3.h> // cross-platform interface for creating a graphical context,
#include <glm/glm.hpp>  // GLM is an optimized math library with syntax to similar to OpenGL Shading Language
#include <glm/gtc/matrix_transform.hpp> // include this to create transformation matrices
#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>


class Camera {
public:
	Camera();
	Camera(glm::vec3 _cameraPosition, glm::vec3 _cameraLookAt, glm::vec3 _cameraUp);
	
	//X
	void setCameraPositionX(float _cameraPosition) { this->cameraPosition.x = _cameraPosition; };
	void setCameraLookAtX(float _cameraLookAt) { this->cameraLookAt.x = _cameraLookAt; };
	void setCameraUpX(float _cameraUp) { this->cameraUp.x = _cameraUp; };

	//Y
	void setCameraPositionY(float _cameraPosition) { this->cameraPosition.y = _cameraPosition; };
	void setCameraLookAtY(float _cameraLookAt) { this->cameraLookAt.y = _cameraLookAt; };
	void setCameraUpY(float _cameraUp) { this->cameraUp.y = _cameraUp; };

	//Z
	void setCameraPositionZ(float _cameraPosition) { this->cameraPosition.z = _cameraPosition; };
	void setCameraLookAtZ(float _cameraLookAt) { this->cameraLookAt.z = _cameraLookAt; };
	void setCameraUpZ(float _cameraUp) { this->cameraUp.z = _cameraUp; };

	//for the vector
	void setCameraPosition(glm::vec3 _cameraPosition) { this->cameraPosition = _cameraPosition; };
	void setCameraUp(glm::vec3 _cameraUp) { this->cameraUp = _cameraUp; };
	void setCameraLookAt(glm::vec3 _cameraLookAt) { this->cameraLookAt = _cameraLookAt; };

	glm::vec3 getCameraPosition() { return this->cameraPosition; };
	glm::vec3 getCameraLookAt() { return this->cameraLookAt; };
	glm::vec3 getCameraUp() { return this->cameraUp; };

private:
	glm::vec3 cameraPosition;
	glm::vec3 cameraLookAt;
	glm::vec3 cameraUp;
};