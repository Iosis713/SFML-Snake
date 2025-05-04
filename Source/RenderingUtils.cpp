module;

import Food;
import Snake;
//#include "../Headers/RenderingUtils.hpp"
#include "../Headers/Config.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

module RenderingUtils;

RenderEngine::RenderEngine()
    : window_(sf::VideoMode(WIDTH, HEIGHT), "SNAKE")
{};

void RenderEngine::addEntity(const std::shared_ptr<Renderable>& entity)
{
    entities.push_back(entity);
}

void RenderEngine::render()
{
    window_.clear();
    for (const auto& entity : entities)
    {
        entity->updatePosition();
        entity->draw(window_);
    }
    window_.display();
}

void SnakeRenderer::draw(sf::RenderWindow& window) const
{
    if (shape_)
        window.draw(*shape_);
    
    for (const auto& tailElement : tail_)
        window.draw(tailElement);
}

void SnakeRenderer::updateTail()
{
    if (tail_.size() < target_->getTailPosition().size())
    {
        const auto& endPosition = target_->getTailPosition().end() - 1;
        sf::RectangleShape rectangleTail(sf::Vector2f(target_->getSize() * 0.8 , target_->getSize() * 0.8));
        rectangleTail.setOrigin(target_->getSize() * 0.4 , target_->getSize() * 0.4);
        rectangleTail.setFillColor(sf::Color::Green);
        rectangleTail.setPosition(endPosition->first, endPosition->second);
        tail_.push_back(rectangleTail);
    }
}

void SnakeRenderer::updatePosition()
{
    updateTail();
    shape_->setPosition(target_->getPosition().first, target_->getPosition().second);
    for(size_t i = 0; i < tail_.size(); i++)
    {
        const auto [xPos, yPos] = target_->getTailPosition().at(i);
        tail_[i].setPosition(xPos, yPos);
    }
};