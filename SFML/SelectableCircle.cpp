#include "SelectableCircle.h"

SelectableCircle::SelectableCircle(int w, int h)
{
	circ = new CircleShape(70);
	circ->setPosition(w, h);
	circ->setOrigin(70, 70);

	deselect();
}

SelectableCircle::SelectableCircle() : SelectableCircle(400, 400)
{}

void SelectableCircle::select()
{
	selected = true;
	circ->setFillColor(Color::Magenta);
}

void SelectableCircle::deselect()
{
	selected = false;
	circ->setFillColor(Color::Cyan);
}

bool SelectableCircle::isSelected()
{
	return selected; 
}

void SelectableCircle::draw(RenderWindow* win)
{
	win->draw(*circ);
}

bool SelectableCircle::isPointInside(Vector2f point)
{
	Vector2f circPosition = circ->getPosition();

	return (circPosition.x - point.x) * (circPosition.x - point.x) + (circPosition.y - point.y) * (circPosition.y - point.y) <=
		circ->getRadius() * circ->getRadius();
}


