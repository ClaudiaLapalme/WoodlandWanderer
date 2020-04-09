#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
		
uniform mat4 worldMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
		
out vec3 Normal;
out vec3 FragPos;
		
void main() {
	mat4 modelViewProjection = projectionMatrix * viewMatrix * worldMatrix;
	gl_Position = modelViewProjection * vec4(aPos, 1.0);
	Normal = mat3(transpose(inverse(worldMatrix))) * aNormal; // inverse and transpose since scaling distorts the normal! 
	FragPos = vec3(modelViewProjection * vec4(aPos, 1.0f));
};