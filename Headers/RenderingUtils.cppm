module;

#include "Config.hpp"
import Food;
import Snake;
#include <SFML/Graphics.hpp>
#include <memory>

export module RenderingUtils;

export class Renderable
{
public:
    virtual ~Renderable() = default;
    Renderable() = default;
    virtual void updatePosition() = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;
};

export template<typename Entity>
class Renderer : public Renderable
{
protected:
    std::shared_ptr<Entity> target_ = nullptr;
    std::unique_ptr<sf::Shape> shape_ = nullptr;

public:
    Renderer() = delete;
    Renderer(const std::shared_ptr<Entity>& target)
        : target_(target)
    {
        shape_ = std::make_unique<sf::CircleShape>(target_->getSize());
        shape_->setOrigin(target_->getSize(), target_->getSize());
        shape_->setFillColor(sf::Color::Red);
    };

    ~Renderer() = default;

    void draw(sf::RenderWindow& window) const override
    {
        if (shape_)
            window.draw(*shape_);
    }

    void updatePosition() override
    {
        shape_->setPosition(target_->getPosition().first, target_->getPosition().second);
    }
};

export class SnakeRenderer : public Renderer<Snake>
{
protected:
    std::vector<sf::RectangleShape> tail_;

public:
    SnakeRenderer() = delete;
    SnakeRenderer(const std::shared_ptr<Snake>& target)
        : Renderer<Snake>(target)
    {
        shape_ = std::make_unique<sf::RectangleShape>(sf::Vector2f(target_->getSize() * 0.8, target_->getSize() * 0.8));
        shape_->setOrigin(target_->getSize() * 0.4 , target_->getSize() * 0.4);
        shape_->setFillColor(sf::Color::Blue);
        shape_->setOutlineThickness(target_->getSize() * 0.2);
        shape_->setOutlineColor(sf::Color::Yellow);
    
        tail_.reserve(target_->getLength());
        for(const auto& tailElement : target_->getTailPosition())
        {
            sf::RectangleShape rectangleTail(sf::Vector2f(target_->getSize() * 0.8 , target_->getSize() * 0.8));
            rectangleTail.setOrigin(target_->getSize() * 0.4 , target_->getSize() * 0.4);
            rectangleTail.setFillColor(sf::Color::Green);
            rectangleTail.setPosition(tailElement.first, tailElement.second);
            tail_.push_back(rectangleTail);
        }
    };
    ~SnakeRenderer() = default;

    void draw(sf::RenderWindow& window) const override;

    void updateTail();
    void updatePosition() override; 
};

export class RenderEngine
{
private:
    sf::RenderWindow window_;
    std::vector<std::shared_ptr<Renderable>> entities;

public:
    RenderEngine();
    ~RenderEngine() = default;

    void addEntity(const std::shared_ptr<Renderable>& entity);
    void render();

    sf::RenderWindow& getWindow() {return this->window_;};
};
