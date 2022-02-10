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
	sf::FloatRect getHitBox() {return sprite.getGlobalBounds();	}
	void update() {
		speed = sf::Vector2f(0.f,0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			speed = sf::Vector2f(-5.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			speed = sf::Vector2f(5.f, 0.f);
		}
		sprite.move(speed);
		sf::Vector2f curr_pos = sprite.getPosition();
		if (curr_pos.x <= getHitBox().width / 2) {
			sprite.setPosition(getHitBox().width / 2, curr_pos.y);
		}
		else if (curr_pos.x >= WINDOW_WIDTH - getHitBox().width/2) {
			sprite.setPosition(WINDOW_WIDTH - getHitBox().width/2,
				curr_pos.y);
		}
	}
};