#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"

class Splash {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Splash() {
		texture.loadFromFile("splash.png");
		sprite.setTexture(texture);
	}
	sf::Sprite getSprite() { return sprite; }
};