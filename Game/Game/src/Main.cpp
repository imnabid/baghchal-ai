#include "AI.cpp"
#include "Platform/Platform.hpp"
#include "includes/game.h"

int main()
{
	sf::RenderWindow window;
	Game game;
	AI ai;
	bool ai_piece = true;

	sf::Event event;
	window.create(sf::VideoMode(1050, 600), "Baagchal");
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				if (!game.get_piece_selected() and game.get_turn() and !ai_piece)
				{
					game.select_tiger(pos.x, pos.y);
				}

				else if (!game.get_piece_selected() and game.get_turn() == 0)
				{
					game.select_goat(pos.x, pos.y);
				}
				else
				{
					game.move_piece(pos.x, pos.y);
					//there is win check at the end
				}
			}
		}

		window.clear();
		window.draw(game);
		window.display();
		if (game.get_turn() == 1 and ai_piece)
		{
			// sf::Time t = sf::seconds(1.2f);
			// sf::sleep(t);
			ai.find_best_move(game);
		}
	}

	return 0;
}
