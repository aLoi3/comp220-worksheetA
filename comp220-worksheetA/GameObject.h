#pragma once

#include "Libraries.h"
#include "Shader.h"
#include "Mesh.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void Update(float deltaTime);
	void Render();

	void SetPosition(float x, float y, float z)
	{
		Position = glm::vec3(x, y, z);
	};

	void SetRotation(float x, float y, float z)
	{
		Rotation = glm::vec3(x, y, z);
	};

	void SetScale(float x, float y, float z)
	{
		Scale = glm::vec3(x, y, z);
	};

	void SetMesh(MeshCollection* meshes)
	{
		Meshes = meshes;
	};

	void SetShader(Shader* shader)
	{
		ShaderProgram = shader;
	};

	void SetDiffuseTexture(GLuint texture)
	{
		DiffuseTexture = texture;
	};

	glm::vec3& GetPosition()
	{
		return Position;
	};

	glm::mat4& GetModelTransformation()
	{
		return ModelMatrix;
	};

	Shader* GetShader()
	{
		return ShaderProgram;
	};

	GLuint GetDiffuseTexture()
	{
		return DiffuseTexture;
	};

private:
	// Set up positions for position, rotation and scale
	glm::vec3 Position;
	glm::vec3 Rotation;
	glm::vec3 Scale;

	// Calculate the translation, rotation and scale matrices using the above vectores
	glm::mat4 TranslationMatrix;
	glm::mat4 RotationMatrix;
	glm::mat4 ScaleMatrix;

	// combine the above matrices into the model matrix (order is important!!!! - TRS)
	glm::mat4 ModelMatrix;

	// Mesh
	MeshCollection* Meshes;

	// Shader
	Shader* ShaderProgram;

	// Texture
	GLuint DiffuseTexture;
};