#include "game.h"
#include "const.h"

Game::Game() {
	window.create(
		sf::VideoMode(
			static_cast<size_t>(WINDOW_WIDTH), 
			static_cast<size_t>(WINDOW_HEIGHT)
		),
		"ITSteps SFML Race",
		sf::Style::Titlebar | sf::Style::Close
	);
	window.setFramerateLimit(FPS);
	road1.init(0.f,0.f);
	road2.init(0.f, -WINDOW_HEIGHT);
	for (int i = 0; i < OBS_QTY; i++) {
		obs[i].init(i*150.f, -i*WINDOW_HEIGHT/2.f);
	}
}
void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Space) 
				if (game_state == SPLASH) game_state = PLAY;
	}
}
void Game::update() {
	switch (game_state) {
	case SPLASH:
		break;
	case PLAY:
		road1.update();
		road2.update();
		car.update();
		for (int i = 0; i < OBS_QTY; i++) {
			obs[i].update();
		}
		break;
	case GAME_OVER:
		break;
	default:
		break;
	}
}
void Game::draw() {
	switch (game_state) {
	case SPLASH:
		window.clear(sf::Color::Black);
		window.draw(splash.getSprite());
		window.display();
		break;
	case PLAY:
		window.clear(sf::Color::Black);
		window.draw(road1.getSprite());
		window.draw(road2.getSprite());
		window.draw(car.getSprite());
		for (int i = 0; i < OBS_QTY; i++) {
			window.draw(obs[i].getSprite());
		}
		window.display();
		break;
	case GAME_OVER:
		window.clear(sf::Color::Black);
		window.draw(splash.getSprite());
		window.display();
		break;
	default:
		break;
	}
}
void Game::check_collisions() {
	for (int i = 0; i < OBS_QTY; i++) {
		if (obs[i].getHitBox().intersects(car.getHitBox())) {
			game_state = GAME_OVER;
		}
	}
}
void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		check_collisions();
		draw();
	}
}