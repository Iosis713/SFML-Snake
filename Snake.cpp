#include "Headers/Global.hpp"
#include "Headers/Snake.hpp"

Snake::Snake(int xPos, int yPos, const int size, const int speed)
    : Food(xPos, yPos, size)
    , speed_(speed)
{
    tailPosition_.reserve(20);
    for(size_t i = 0; i < lenght_ - 1; i++)
    {
        tailPosition_.push_back(position_);
        tailPosition_[i].first -= (int)i * (int)CELL_SIZE;
    }
};

bool Snake::checkFoodAndSnakeCollision(Food& food)
{
    for(auto tailElement : tailPosition_)
    {
        if(food.getPosition() == tailElement or food.getPosition() == position_)
        {
            return true;
        }
    }
    return false;
}

void Snake::draw(sf::RenderWindow& i_window, sf::Color color)
{   
    //Yellow circuit
    sf::RectangleShape rectangleBack(sf::Vector2f(getSize(), getSize()));
    rectangleBack.setOrigin(getSize() * 0.5, getSize() * 0.5);
    rectangleBack.setFillColor(sf::Color::Yellow);
    rectangleBack.setPosition(position_.first, position_.second);
    //Green core
    sf::RectangleShape rectangleHead(sf::Vector2f(getSize()*0.8 , getSize()*0.8));
    rectangleHead.setOrigin(getSize() * 0.4 , getSize() * 0.4);
    rectangleHead.setFillColor(color);
    rectangleHead.setPosition(position_.first, position_.second);
    
    i_window.draw(rectangleBack);
    i_window.draw(rectangleHead);

    for(auto element : tailPosition_)
    {
        sf::RectangleShape rectangleTail(sf::Vector2f(getSize()*0.8 , getSize()*0.8));
        rectangleTail.setOrigin(getSize() * 0.4 , getSize() * 0.4);
        rectangleTail.setFillColor(sf::Color::Green);
        rectangleTail.setPosition(element.first, element.second);
        i_window.draw(rectangleTail);
    }
}

void Snake::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                                  && previousDirection_ != Direction::Down)
    {
        direction_ = Direction::Up;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                                        && previousDirection_ != Direction::Up)
    {
        direction_ = Direction::Down;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
                                        && previousDirection_ != Direction::Right)
    {
        direction_ = Direction::Left;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                                        && previousDirection_ != Direction::Left)
    {
        direction_ = Direction::Right;
    }
}

void Snake::updatePreviousDirection()
{
    previousDirection_ = direction_;
}

void Snake::move()
{
    
    std::vector<std::pair<int, int>> temporary;
    temporary.reserve(tailPosition_.capacity());
    temporary = tailPosition_;
    tailPosition_[0] = position_;
    
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
   
    for(size_t i = 1; i < lenght_; i++)
    {
        tailPosition_[i] = temporary[i-1];
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
        std::vector<std::pair<int, int>> temporary;
        temporary.reserve(tailPosition_.capacity() + 1);
        temporary = tailPosition_;
        tailPosition_.push_back(*temporary.end());
        food.kill();
        
        while(checkFoodAndSnakeCollision(food))
        {
            food.kill();
        }
        return true;
    }
    else{return false;}
}

size_t Snake::getLenght(){ return lenght_; }

