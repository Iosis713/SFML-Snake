#include "Headers/Config.hpp"
import Food;
import Snake;
import Controller;
import RenderingUtils;
#include <SFML/Graphics.hpp>

/*
#include "Headers/Food.hpp"
#include "Headers/Snake.hpp"
#include "Headers/Controller.hpp"
#include "Headers/RenderingUtils.hpp"
*/
#include <chrono>
#include <iostream>
#include <thread>

int main()
{  
    RenderEngine renderEngine{};

    auto food = std::make_shared<Food>(20, 140, CELL_SIZE/2);
    auto snake = std::make_shared<Snake>(60, 180, CELL_SIZE);
    Controller controller(snake);
    auto foodRenderer = std::make_shared<Renderer<Food>>(food);
    auto snakeRenderer = std::make_shared<SnakeRenderer>(snake);
    renderEngine.addEntity(foodRenderer);
    renderEngine.addEntity(snakeRenderer);
    
    std::chrono::time_point<std::chrono::steady_clock> lastScreenRefresh = std::chrono::steady_clock::now();
    unsigned deltaTime;
    
    auto& window = renderEngine.getWindow();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            {
               if (event.type == sf::Event::Closed){
                    window.close();
               }
            }

        window.clear();
        lastScreenRefresh = std::chrono::steady_clock::now(); 

        snake->updatePreviousDirection();
        do
        {
            snake->update(controller.control());
            deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - lastScreenRefresh).count();   
        }while (FRAME_DURATION > deltaTime);

        snake->isFoodAte(*food);
        snake->move();

        renderEngine.render();

        if(snake->isTailAte())
        {   
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(5s);
            return 0;
        }
    }
    return 0;
}

