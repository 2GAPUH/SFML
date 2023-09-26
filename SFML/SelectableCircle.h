#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class SelectableCircle
{
	CircleShape* circ;
	bool selected;

public:
	SelectableCircle(int w, int h);
	SelectableCircle();
	void select();
	void deselect();
	bool isSelected();
	void draw(RenderWindow* win);
	bool isPointInside(Vector2f point);
};