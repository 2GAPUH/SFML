#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "SelectableCircle.h"
#include <vector>

class GameCore
{
	RenderWindow* win;
	std::vector<SelectableCircle*> circles;

	void update(int elapsed);
	void draw();

public:
	GameCore(int w, int h);
	GameCore();
	~GameCore();
	void start();
};

