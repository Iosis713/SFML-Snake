#include "Headers/Food.hpp"

Food::Food(const int size)
    : size_(size)
{
    position_ = {20, 140};
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

void Food::kill(const int& mapWidth, const int& mapHeight, const int& cellSize)
{   
    /*
    int getRandom(const int& upperLimit); 
    int getRandom(const int& upperLimit)
        {
            std::random_device randDev;
            std::mt19937 randGenerator(randDev());
            std::uniform_int_distribution<int> dist((int) 0, upperLimit);
            return dist(randGenerator);
        }
    */
    setIsAlive(false);

    setPosition(getRandom(mapWidth/cellSize - 1) * cellSize + cellSize/2,
                getRandom(mapHeight/cellSize - 1) * cellSize + cellSize/2);
    
    setIsAlive(true);
}

int Food::getRandom(const int& upperLimit)
{
    std::random_device randDev;
    std::mt19937 randGenerator(randDev());
    std::uniform_int_distribution<int> dist((int) 0, upperLimit);
    return dist(randGenerator);
}

