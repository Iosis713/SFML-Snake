#include "Food.hpp"
 
void Food::setIsAlive(bool life)
{
    isAlive = life;
}


bool Food::getIsAlive() {return isAlive;}
float Food::getRadius() {return radius;}
void Food::setPosition(const size_t& xPos,const size_t& yPos)
{
    position_.first = xPos;
    position_.second = yPos;
}
std::pair<size_t, size_t> Food::getPosition() {return position_;}

void Food::draw(sf::RenderWindow& i_window)
{
    sf::CircleShape circle(getRadius());
    circle.setOrigin(getRadius(), getRadius());
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(position_.first, position_.second);
    i_window.draw(circle);
}

void Food::kill()
{
    setIsAlive(false);
}

