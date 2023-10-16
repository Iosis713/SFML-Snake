#include "Headers/Global.hpp"
#include "Headers/Snake.hpp"

Snake::Snake(int xPos, int yPos, const int size, const int speed)
    : Food(xPos, yPos, size)
    , speed_(speed)
{};

void Snake::draw(sf::RenderWindow& i_window)
{   
    //Yellow circuit
    sf::RectangleShape rectangleBack(sf::Vector2f(getSize(), getSize()));
    rectangleBack.setOrigin(getSize() * 0.5, getSize() * 0.5);
    rectangleBack.setFillColor(sf::Color::Yellow);
    rectangleBack.setPosition(position_.first, position_.second);
    //Green core
    sf::RectangleShape rectangle(sf::Vector2f(getSize()*0.8 , getSize()*0.8));
    rectangle.setOrigin(getSize() * 0.4 , getSize() * 0.4);
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(position_.first, position_.second);
    
    i_window.draw(rectangleBack);
    i_window.draw(rectangle);
}

void Snake::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction_ != Direction::Down){
        direction_ = Direction::Up;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction_ != Direction::Up){
        direction_ = Direction::Down;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction_ != Direction::Right){
        direction_ = Direction::Left;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction_ != Direction::Left){
        direction_ = Direction::Right;
    }
}

void Snake::move()
{
    switch(direction_)
    {
        case Direction::Up:
            position_.second -= speed_ * CELL_SIZE;
            break;

        case Direction::Down:
            position_.second += speed_ * CELL_SIZE;
            break;

        case Direction::Left:
            position_.first -= speed_ * CELL_SIZE;
            break;

        case Direction::Right:
            position_.first += speed_ * CELL_SIZE;
            break;
    }
    checkIfInsideTheMap();
}

void Snake::checkIfInsideTheMap()
{
    if(position_.first > 0.5 * size_ && 
      position_.first < WIDTH - 0.5 * size_ &&
      position_.second > +0.5 * size_ && 
      position_.second < HEIGHT - 0.5 * size_){}

    else if(position_.first < 0.5 * size_)
    {
        position_.first = WIDTH - 0.5 * size_; //0.5*size so it does not "teleport"
    }
    
    else if(position_.first > WIDTH - 0.5 * size_)
    {
        position_.first = 0.5 * size_;
    }

    else if(position_.second < 0.5 * size_)
    {
        position_.second = HEIGHT - 0.5 * size_;
    }

    else if(position_.second > HEIGHT - 0.5 * size_)
    {
        position_.second = 0.5 * size_;
    }
}

bool Snake::isFoodAte(Food& food)
{
    if(getPosition() == food.getPosition())
    {
        lenght_++;
        food.kill();    
        return true;
    }
    else{return false;}
}

size_t Snake::getLenght(){ return lenght_; }

