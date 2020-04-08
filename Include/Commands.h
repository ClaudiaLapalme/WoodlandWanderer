#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>

class Commands {
public:
	static void closeWindow(GLFWwindow* window);
	static void setRenderingMode(GLFWwindow* window);
	static void processCameraDirection(GLFWwindow* window, glm::vec3& cameraPos, glm::vec3& cameraLookAt, glm::vec3& cameraUp, float deltaTime);
	static void processCameraRoamDirection(GLFWwindow* window, glm::vec3& cameraPos, glm::vec3& cameraLookAt, glm::vec3& cameraUp, float deltaTime);

	glm::vec3 getCameraPos() { return cameraRoamPosition; };

private: 
	glm::vec3 cameraRoamPosition = glm::vec3(3.0f, 5.0f, 25.0f);
};