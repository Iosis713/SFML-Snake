#include "Food.hpp"
 
void Food::setIsAlive(bool life)
{
    isAlive = life;
}


bool Food::getIsAlive() {return isAlive;}
void Food::setPosition(size_t xPos,size_t yPos)
{
    position_.first = xPos;
    position_.second = yPos;
}
std::pair<size_t, size_t> Food::getPosition() {return position_;}

void Food::draw(sf::RenderWindow& i_window)
{
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Red);
    i_window.draw(circle);
}

//KofyBrek pacman
//sf::CircleShape circle(50);
//circle.setFillColor(sf::Color::Blue);

//shape_.::setFillColor(sf::Color::Red);


