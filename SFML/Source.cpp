#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow win(VideoMode(500, 500), "SFML_WINDOW");
    Event ev;


    while (win.isOpen())
    {
       
        while (win.pollEvent(ev))
        {
            if (ev.type == Event::Closed)
                win.close();
        }

        win.clear();
        win.display();
    }

    return 0;
}