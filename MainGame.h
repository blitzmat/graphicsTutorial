#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <vector>

#include <Bengine/Errors.h>
#include <Bengine/ImageLoader.h>
#include <Bengine/Window.h>
#include <Bengine/GLSLProgram.h>
#include <Bengine/GLTexture.h>
#include <Bengine/Camera2D.h>
#include <Bengine/SpriteBatch.h>

enum class GameState { PLAY, EXIT };

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();


private:
	void initSystems();
	void initShaders();
	void gameLoop();
	void processInput();
	void drawGame();
	void calculateFPS();

	Bengine::Window _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;
	float _time;
	
	Bengine::GLSLProgram _colorProgram;
	Bengine::Camera2D _camera;
	Bengine::SpriteBatch _spriteBatch;

	float _fps;
	float _frameTime;
	float _maxFPS;

};

