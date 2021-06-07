#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "game.h"
#include "rabbit.h"
#include "menu.h"



int main()
{
        srand(static_cast<unsigned>(time(0)));

        sf::RenderWindow window(sf::VideoMode(600, 600), "menu");
Game game;
   bool     isMenu = true;

        Menu menu(window.getSize().x, window.getSize().y);

        while (window.isOpen())
        {
            sf::Event event;

            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        if (isMenu)
                        {
                            menu.MoveUp();
                        }
                        break;

                    case sf::Keyboard::Down:
                        if (isMenu)
                        {
                            menu.MoveDown();
                        }
                        break;

                    case sf::Keyboard::Return:
                        if (isMenu)
                        {
                            switch (menu.GetPressedItem())
                            {
                            case 0:


                                isMenu = false;

                                break;
                            case 1:
                                std::cout << "Option button has been pressed" << std::endl;
                                break;
                            case 2:
                                window.close();
                                break;
                            }
                        }
                        break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
                }
            }

            window.clear();
            if (isMenu)
            {
                menu.draw(window);

;            }
            else
            {
                game.update(window);
                game.render(window);
            }
            window.display();
        }
    }
