#pragma once
#include "SFML/Graphics.hpp"

class Road {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed = sf::Vector2f(0.0f, 3.0f);
public:
	Road() {
		texture.loadFromFile("road.jpg");
		sprite.setTexture(texture);
		sprite.setScale(1.f, 1.67f);
	}
	void init(float startx, float starty) { sprite.setPosition(startx, starty); }
	sf::Sprite getSprite() { return sprite; }
	void update() {
		sprite.move(speed);
		if (sprite.getPosition().y >= WINDOW_HEIGHT) {
			sprite.setPosition(0.f, -WINDOW_HEIGHT);
		}
	}
};