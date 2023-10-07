#include <iostream>
#include "Food.hpp"
#include <random>

const size_t WIDTH = 1280;
const size_t HEIGHT = 800;

size_t getRandom(const float& lowerLimit, const size_t& upperLimit);

int main(){
    //SFML test    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SSSNAKE!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);
    
    std::string status;
    Food food;
    

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
        window.draw(shape);

        //food.setPosition(WIDTH/2, HEIGHT/2);
        food.draw(window);
        window.display();
        std::cin >> status;
        if (status == "kill"){
            food.kill();
            std::cout << "Food killer" << ", Food status: " << food.getIsAlive() << '\n';
            std::cout << "Food restored, new position is set\n";
            food.setIsAlive(true);
            std::cout << "Food status: " << food.getIsAlive() << '\n';
            food.setPosition(getRandom(food.getRadius(), WIDTH - food.getRadius()),
                             getRandom(food.getRadius(), HEIGHT - food.getRadius()));

            std::cout << "New Position: " << food.getPosition().first << " " 
                                          << food.getPosition().second << '\n';
            //auto random1 = g;
            //auto random2 = g;
            //https://stackoverflow.com/questions/27759891/how-to-run-mersenne-twister-inside-a-function
            //food.setPosition(getRand(0,WIDTH), getRand(0,WIDTH))
            //std::cout <<"random1 = " << random1 << " random2= " << random2 << '\n';

            //food.setPosition(static_cast<size_t>(random1), static_cast<size_t>(random2));
        }
        else if(status == "quit"){
            return 0;
        }
    }

    return 0;
}


size_t getRandom(const float& lowerLimit, const size_t& upperLimit)
{
    std::random_device randDev;
    std::mt19937 twister(randDev());
    std::uniform_int_distribution<size_t> dist((size_t) lowerLimit, upperLimit);
    //std::cout << upper << " " << twister << '\n';
    return dist(twister);
}

