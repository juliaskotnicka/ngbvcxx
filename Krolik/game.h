#ifndef GAME_H
#define GAME_H


#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "rabbit.h"
#include <vector>
#include <sstream>
#include "ball.h"
#include <SFML/Audio.hpp>

class Game
{
private:

    sf::VideoMode videoMode;

    bool endGame;
std::vector<Ball> balls;
float time;
float maxtime;
int maxball;

sf::Texture backgroundTexture;
sf::Sprite  background;
sf::Music music;
sf::Text endText;

    void initVariables();

    void initBackground();
    void initMusic();
    void initRabbit();
    void initFont();
    void initText();



public:
    Game();
    ~Game();
    sf::Event event;
       void initWindow();
    Rabbit* rabbit;
    int points;
    sf::Font font;
    sf::Text text;
    const bool& GameEnd();
    const  bool open(sf::RenderWindow& window) const;
    void pollEvents(sf::RenderWindow& window);
    void createball(sf::RenderWindow& window);
    void updateRabbit(sf::RenderWindow &window);
    int randomize() ;
    void remove();
    void moving();
    void renderBackground(sf::RenderWindow &window);
    void rendertext(sf::RenderTarget& target);
    void updatePoints();
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
};

#endif // GAME_H
