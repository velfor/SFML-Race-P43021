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
	road1.init(0.f,0.f);
	road2.init(0.f, -WINDOW_HEIGHT);
}
void Game::play() {
	while (window.isOpen()) {
		//1 обработка событий
		sf::Event event;
		while (window.pollEvent(event)) {
			// ѕользователь нажал на Ђкрестикї и хочет закрыть окно?
			if (event.type == sf::Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//2 update
		road1.update();
		road2.update();
		//3 отрисовка окна
		window.clear(sf::Color::Black);
		window.draw(road1.getSprite());
		window.draw(road2.getSprite());
		window.display();
	}
}