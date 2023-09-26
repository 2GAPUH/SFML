#include "GameCore.h"

void GameCore::update(int elapsed)
{
	Event ev;
	while (win->pollEvent(ev))
	{
		switch (ev.type)
		{
		case Event::Closed:
			win->close();
			break;

		case Event::MouseButtonPressed:
			switch(ev.mouseButton.button)
			{ 
			case Mouse::Left:
				circles.push_back(new SelectableCircle(ev.mouseButton.x, ev.mouseButton.y));
				break;

			case Mouse::Right:
				for (auto circ : circles)
				{
					if (circ->isPointInside(Vector2f(ev.mouseButton.x, ev.mouseButton.y)))
						circ->select();
					else
						circ->deselect();

				}
				break;
			}
			break;
		}

	}
}

void GameCore::draw()
{
	win->clear();

	for(auto circ : circles)
	{ 
	circ->draw(win);
	}

	win->display();
}

GameCore::GameCore(int w, int h)
{
	win = new RenderWindow(VideoMode(w, h), "SFML Window");
}

GameCore::GameCore() : GameCore(600, 600)
{
}

GameCore::~GameCore()
{
	delete win;
}


void GameCore::start()
{
	Clock clc;
	while (win->isOpen())
	{
		int elapsed = clc.restart().asMilliseconds();
		update(elapsed);

		draw();
	}
}