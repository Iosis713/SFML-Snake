#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class Food
{
protected:
    std::pair<int, int> position_;
    const int size_;
    std::unique_ptr<sf::Shape> shape_ = nullptr;

public:
    Food() = delete;
    Food(const Food& food) = delete;
    Food(const int size, int xPos, int yPos);
    ~Food() = default;

    void draw(sf::RenderWindow& i_window); 
    virtual void setPosition(const int& xPos,const int& yPos);
    virtual std::pair<int, int> getPosition() const {return this->position_;};
    virtual int getRandom(const int upperLimit);
    void kill();
};
