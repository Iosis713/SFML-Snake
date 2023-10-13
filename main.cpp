#include "Headers/Food.hpp"
#include "Headers/Snake.hpp"

#include <chrono>
#include <iostream>
#include <random>
#include <thread>

const int WIDTH = 1280;
const int HEIGHT = 800;

int getRandom(const int& lowerLimit, const int& upperLimit);
auto refresh = [](){using namespace std::chrono_literals;
                       std::this_thread::sleep_for(20ms);};

int main(){  
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SNAKE");

    std::string status;
    Food food(50);
    Snake snake(5, 100);

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
        snake.update(WIDTH, HEIGHT);
        snake.draw(window);
        window.display();
        
        std::cout << "Snake (x, y) = (" << snake.getPosition().first << ", "
                  << snake.getPosition().second << ")\n";


        refresh();  
    }

    return 0;
}

/*************************************************************************************/

int getRandom(const int& lowerLimit, const int& upperLimit)
{
    std::random_device randDev;
    std::mt19937 randGenerator(randDev());
    std::uniform_int_distribution<int> dist((int) lowerLimit, upperLimit);
    return dist(randGenerator);
}

