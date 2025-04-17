#pragma once
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

class Food
{
protected:
    bool isAlive_ = true;
    std::pair<int, int> position_;
    const int size_;

public:
    Food() = delete;
    Food(const int size, int xPos, int yPos);
    ~Food() = default;

    void draw(sf::RenderWindow& i_window);
    virtual void setIsAlive(bool life);    
    virtual void setPosition(const int& xPos,const int& yPos);
    bool getIsAlive();
    std::pair<int, int> getPosition();
    virtual int getRandom(const int upperLimit);
    float getSize();    

    void kill();
};

