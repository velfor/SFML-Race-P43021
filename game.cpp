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
		//1 ��������� �������
		sf::Event event;
		while (window.pollEvent(event)) {
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == sf::Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		//2 update
		road1.update();
		road2.update();
		//3 ��������� ����
		window.clear(sf::Color::Black);
		window.draw(road1.getSprite());
		window.draw(road2.getSprite());
		window.display();
	}
}