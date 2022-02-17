#include "Home_Page.h"
#include "Platform/Platform.hpp"

#include "Audio.h"

int main()
{
	Home home;
	Audio audio("content/deep.wav", 30);

	audio.play();
	sf::RenderWindow window(sf::VideoMode(1050, 600), "BaghChal");

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				// std::cout << "Key is pressed" << std::endl;
				window.close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				if (home.mute_button_clicked(pos.x, pos.y))
				{
					home.change_sound_state(audio);
				}
			}
			if (event.type == sf::Event::MouseMoved)
			{
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				if (home.play_button_hover(pos.x, pos.y))
				{
					home.change_play_button();
				}
			}
		}

		window.clear();
		window.draw(home);
		window.display();
	}

	return 0;
}
