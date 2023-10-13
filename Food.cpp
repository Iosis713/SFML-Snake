#include "Headers/Food.hpp"

Food::Food(const int size)
    : size_(size)
{
    position_ = {50, 170};
}


void Food::setIsAlive(bool life)
{
    isAlive_ = life;
}


bool Food::getIsAlive() {return isAlive_;}
float Food::getSize() {return size_;}
void Food::setPosition(const int& xPos, const int& yPos)
{
    position_.first = xPos;
    position_.second = yPos;
}
std::pair<int, int> Food::getPosition() {return this->position_;}

void Food::draw(sf::RenderWindow& i_window)
{
    sf::CircleShape circle(getSize());
    circle.setOrigin(getSize(), getSize());
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(position_.first, position_.second);
    i_window.draw(circle);
}

void Food::kill()
{
    setIsAlive(false);
}

