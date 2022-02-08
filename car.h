#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"

class Car{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed = sf::Vector2f(5.0f, 0.0f);
public:
	Car() {
		texture.loadFromFile("car.png");
		sprite.setTexture(texture);
		sf::FloatRect local_bounds = sprite.getLocalBounds();
		sprite.setOrigin(local_bounds.width / 2.f, 
			local_bounds.height / 2.f);
		sprite.setScale(0.12f, 0.12f);
		sprite.setRotation(90.f);
		sf::FloatRect global_bounds = sprite.getGlobalBounds();
		sprite.setPosition(
			WINDOW_WIDTH / 2.f,
			WINDOW_HEIGHT - global_bounds.height / 2 - 20
		);

	}
	sf::Sprite getSprite() { return sprite; }
};