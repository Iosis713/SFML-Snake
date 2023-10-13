#include "Headers/Food.hpp"
#include "Headers/Snake.hpp"

#include <chrono>
#include <iostream>
#include <random>
#include <thread>

const size_t WIDTH = 1280;
const size_t HEIGHT = 800;

size_t getRandom(const float& lowerLimit, const size_t& upperLimit);
auto refresh = [](){using namespace std::chrono_literals;
                       std::this_thread::sleep_for(20ms);};

int main(){  
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SNAKE");

    std::string status;
    Food food;
    Snake snake(100/20);

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
        
        food.draw(window);
        snake.draw(window);
        window.display();
        /*
        std::cin >> status;
        
        if (status == "kill"){
            food.kill();
            std::cout << "Food killer" << ", Food status: " << food.getIsAlive() << '\n';
            std::cout << "Food restored, new position is set\n";
            food.setIsAlive(true);
            std::cout << "Food status: " << food.getIsAlive() << '\n';
            food.setPosition(getRandom(food.getSize(), WIDTH - food.getSize()),
                             getRandom(food.getSize(), HEIGHT - food.getSize()));

            std::cout << "New Position: " << food.getPosition().first << " " 
                                          << food.getPosition().second << '\n';     
        }
        else if(status == "quit"){
            return 0;
        }
        
        snake.setPosition(snake.getPosition().first + snake.speed_,
                          snake.getPosition().second);
        */

        snake.update();

        refresh();  
    }

    return 0;
}

/*************************************************************************************/

size_t getRandom(const float& lowerLimit, const size_t& upperLimit)
{
    std::random_device randDev;
    std::mt19937 randGenerator(randDev());
    std::uniform_int_distribution<size_t> dist((size_t) lowerLimit, upperLimit);
    return dist(randGenerator);
}

