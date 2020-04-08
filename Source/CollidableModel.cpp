#include "..\Include\CollidableModel.h"

/**
* CollidableModel Constructor
*/
CollidableModel::CollidableModel(GLuint VAO, GLuint colliderVAO, GLuint numVertices, glm::vec3 color) 
	: Model(VAO, numVertices, color), colliderVAO(colliderVAO), colliderTransformMatrix(colliderTransformMatrix) { }

/**
* CollidableModel destructor
*/
CollidableModel::~CollidableModel() {}

/**
* Overrides the Model's setter for the ModelTransformationMatrix to polymorphically set the collider's box.
* This is to ensure that the box's transformations match the model's transformation.
*/
void CollidableModel::setModelTransformMatrix(glm::mat4 modelTransformMatrix) { 
	
	Model::setModelTransformMatrix(modelTransformMatrix);
	this->colliderTransformMatrix = modelTransformMatrix; 
};

/**
* DEBUG: Overloading Model::draw() to draw the collider box
*/
void CollidableModel::draw(const GLuint& worldMatrixLocation, const GLuint& colorLocation) {
	// This is for drawing collidable object
	glDisable(GL_CULL_FACE);

	glBindVertexArray(this->getVAO());
	glBindBuffer(GL_ARRAY_BUFFER, this->getVAO());

	glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &(this->getModelTransformMatrix())[0][0]);
	glUniform3fv(colorLocation, 1, value_ptr(this->getColor()));

	glDrawArrays(GL_TRIANGLES, 0, this->getNumVertices());

	// This is for drawing the collider box for Debugging

	glBindVertexArray(this->getColliderVAO());
	glBindBuffer(GL_ARRAY_BUFFER, this->getColliderVAO());

	glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &(this->getColliderTransformMatrix())[0][0]);
	glUniform3fv(colorLocation, 1, value_ptr(glm::vec3(1.0f, 1.0f, 1.0f)));

	glDrawArrays(GL_TRIANGLES, 0, 36);
	glEnable(GL_CULL_FACE);
}

glm::vec3 CollidableModel::getColliderPosition() {
	glm::mat4 transformation;
	glm::vec3 scale;
	glm::quat rotation;
	glm::vec3 translation;
	glm::vec3 skew;
	glm::vec4 perspective;
	glm::decompose(transformation, scale, rotation, translation, skew, perspective);

	return translation;
}

glm::vec3 CollidableModel::getColliderScale() {
	glm::mat4 transformation;
	glm::vec3 scale;
	glm::quat rotation;
	glm::vec3 translation;
	glm::vec3 skew;
	glm::vec4 perspective;
	glm::decompose(transformation, scale, rotation, translation, skew, perspective);

	return scale;
}