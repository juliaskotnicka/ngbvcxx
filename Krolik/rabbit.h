#ifndef RABBIT_H
#define RABBIT_H

#include <SFML/Graphics.hpp>


class Rabbit
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float speed;
    void initVariables();
    void initTexture();
    void initSprite();
    int maxlives;
    int lives;


public:
    Rabbit();
    virtual ~Rabbit();
    const bool collision();
    sf::FloatRect getBounds() const;
    const int& getLives();
    const int& getmaxLives();
    void takelife(const int life);
    void givelife(const int health);
    void move(const float dirX, const float dirY);
    void bounds(const sf::RenderTarget& target);
    void update(const sf::RenderTarget& target);
    void render(sf::RenderTarget& target);
};
#endif // RABBIT_H
