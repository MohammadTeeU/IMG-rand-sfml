#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<random>
#include<iostream>
#include <SFML/Window/Touch.hpp>

int main(int argc, char *argv[])
{

	 sf::VideoMode screen(sf::VideoMode::getDesktopMode());

    sf::RenderWindow win(screen, "");
    win.setFramerateLimit(30);


	int x=10,y=10;//size of img
	

	///random number for each pixl (color)
	std::random_device d;
	std::mt19937 rand(d());
	std::uniform_int_distribution<std::mt19937::result_type> rng(0,255);//range of color


	///create pixls
	sf::Uint8 pix[x*y*4];

	for(int i=0;i<x*y*4;i++)
	{
		pix[i]=rng(rand);
	}
	///create img
	sf::Image img;
	img.create(x,y,pix);

	////make img in texture
	sf::Texture tex;
	tex.loadFromImage(img);

	//////set tex to  rect.
	sf::RectangleShape block(sf::Vector2f(screen.width,screen.height));
	block.setTexture(&tex);


	while(win.isOpen())
	{
		sf::Event ev;
		while(win.pollEvent(ev))
		{
			if(ev.type==sf::Event::Closed)
			  win.close();
		}
		/////////
		win.clear();
		win.draw(block);
		win.display();
		///reset

		for(int i=0;i<x*y*4;i++)
			{
				pix[i]=rng(rand);
			}
		img.create(x,y,pix);
		tex.loadFromImage(img);
		block.setTexture(&tex);

	}

return 0;
}
