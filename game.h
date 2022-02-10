#pragma once
#include "SFML/Graphics.hpp"
#include "road.h"
#include "car.h"
#include "splash.h"
#include "obstacle.h"

class Game {
public:
	enum GameState {SPLASH, PLAY, GAME_OVER};
	Game();
	void play();
private:
	sf::RenderWindow window;
	GameState game_state = SPLASH;
	Splash splash;
	Road road1, road2;
	Car car;
	Obstacle obs[OBS_QTY];

	void check_events();
	void update();
	void draw();
	void check_collisions();
};