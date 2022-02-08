#pragma once
#include "SFML/Graphics.hpp"
#include "road.h"
#include "car.h"

class Game {
public:
	Game();
	void play();
private:
	sf::RenderWindow window;
	Road road1, road2;
	Car car;
};