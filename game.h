#pragma once
#include "SFML/Graphics.hpp"
#include "road.h"

class Game {
public:
	Game();
	void play();
private:
	sf::RenderWindow window;
	Road road1, road2;
};