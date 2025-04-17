#include "Headers/Food.hpp"
#include "Headers/Global.hpp"
#include <stdexcept>

Food::Food(int xPos, int yPos, const int size)
    : position_(xPos, yPos)
    , size_(size)
{}

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
    setPosition(getRandom(WIDTH/CELL_SIZE - 1) * CELL_SIZE + CELL_SIZE/2,
                getRandom(HEIGHT/CELL_SIZE - 1) * CELL_SIZE + CELL_SIZE/2);
}

int Food::getRandom(const int upperLimit)
{
    if (upperLimit < 0)
        throw std::runtime_error("Upper limit has to be higher than 0!\n");

    std::random_device randDev;
    std::mt19937 randGenerator(randDev());
    std::uniform_int_distribution<int> dist((int) 0, upperLimit);
    return dist(randGenerator);
}

