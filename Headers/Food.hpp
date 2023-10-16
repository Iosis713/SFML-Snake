#pragma once
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

class Food
{
protected:
    std::pair<int, int> position_;
    bool isAlive_ = true;
    const int size_ = 50;
    //sf::CircleShape circle2;

public:
    Food(const int size);
    ~Food() = default;

    void draw(sf::RenderWindow& i_window);
    void setIsAlive(bool life);    
    void setPosition(const int& xPos,const int& yPos);
    float getSize();    

    void kill(const int& mapWidth, const int& mapHeight, const int& cellSize);
    bool getIsAlive();
    std::pair<int, int> getPosition();
    int getRandom(const int& upperLimit);
};

