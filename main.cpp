#include <SFML/Graphics.hpp>
#include "square.hpp"
#include <vector>

using namespace sf;
using namespace std;

// struct Vector2f
//{
// float x;
// float y;
//};

Vector2f speed = {3.f, 3.f};

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    Square shape({50.f, 30.f});

    window.setFramerateLimit(120);

    vector <Square> squares;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    int w = rand() % 50;
                    int h = rand() % 50;
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    Square squ(Vector2f(w, h), x, y);
                    squares.push_back(squ);
                }
            }
        }
    


window.clear();
shape.update();
shape.drawTo(window);
for (auto &r : squares)
{
    r.update();
    r.drawTo(window);
}
window.display();
    }

return 0;
}