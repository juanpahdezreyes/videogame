#include "square.hpp"

Square::Square(Vector2f size)
{
    this->shape = RectangleShape(size);
    this->shape.setFillColor(Color::Blue);
    this->speed = Vector2f(3.f, 3.f);
    this->acc = Vector2f(0.f, 1.f);
}

Square::Square(Vector2f size, int x, int y)
{
    this->shape = RectangleShape(size);
    this->shape.setFillColor(Color::Blue);
    this->shape.setPosition(Vector2f(x, y));
    this->speed = Vector2f(3.f, 3.f);
    this->acc = Vector2f(0.f, 1.f);
}

void Square::update()
{
    this->speed += this->acc;
    this->shape.move(speed);
    Vector2f position = this->shape.getPosition();
    // this->shape.setPosition(position + this->speed);

    if (this->shape.getPosition().x + this->shape.getSize().x >= 800 ||
        this->shape.getPosition().x < 0)
        this->speed.x *= -1;

    if (this->shape.getPosition().y + this->shape.getSize().y >= 600 ||
        this->shape.getPosition().y < 0)
    {
        this->speed.y *= -1;
        Vector2f position = this->shape.getPosition();
        this->shape.setPosition(position.x, 600 - this->shape.getSize().y);
    }
}

void Square::drawTo(RenderWindow &window)
{

    window.draw(this->shape);
}