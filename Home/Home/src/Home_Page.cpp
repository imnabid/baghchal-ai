#include "Home_Page.h"

Home ::Home()
{
	sound_image = "content/unmute.png";
	play_button = "content/play.png";
	home_t.loadFromFile("content/home.jpg");
	home_s.setTexture(home_t);
	soundbutton_t.loadFromFile(sound_image);
	soundbutton_s.setTexture(soundbutton_t);
	soundbutton_s.setPosition(925, 5);

	playbutton_t.loadFromFile(play_button);
	playbutton_s.setTexture(playbutton_t);
	playbutton_s.setPosition(370, 300);
}

void Home::change_sound_state(Audio& audio)
{
	if (sound_image == "content/unmute.png")
	{
		sound_image = "content/mute.png";
		audio.pause();
	}
	else
	{
		sound_image = "content/unmute.png";
		audio.play();
	}

	soundbutton_t.loadFromFile(sound_image);
	soundbutton_s.setTexture(soundbutton_t);
}

bool Home::mute_button_clicked(int x, int y)
{
	sf::FloatRect button = soundbutton_s.getGlobalBounds();
	if (button.contains(x, y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Home::change_play_button()
{
	if (play_button == "content/play.png")
	{
		play_button = "content/play_hover.png";
	}
	else
	{
		play_button = "content/play.png";
	}

	playbutton_t.loadFromFile(play_button);
	playbutton_s.setTexture(playbutton_t);
}

bool Home::play_button_hover(int x, int y)
{
	sf::FloatRect button = playbutton_s.getGlobalBounds();
	if (button.contains(x, y))
	{
		return true;
	}
	else
	{
		return false;
	}
}