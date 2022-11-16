#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Bengine {
	class Camera2D
	{
	public:
		Camera2D();
		~Camera2D();

		void init(int screenWidth, int screenHeight);
		void update();

		void setPosition(const glm::vec2& newPosition) { _position = newPosition; _needsMatrixUpdate = true; }
		void setScale(float newScale) { _scale = newScale; _needsMatrixUpdate = true; }

		glm::vec2 getPosition() { return _position; }
		float getScale() { return _scale; }
		glm::mat4 geCameraMatrix() { return _cameraMatrix; }

	private:
		float _scale;
		glm::vec2 _position;
		glm::mat4 _cameraMatrix;
		glm::mat4 _orthoMatrix;
		bool _needsMatrixUpdate;
		int _screenWidth;
		int _screenHeight;
	};
}

