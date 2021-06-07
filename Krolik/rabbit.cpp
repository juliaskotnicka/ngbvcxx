#include "game.h"
#include <SFML/Graphics.hpp>




void Rabbit::initVariables()
{
this->speed=4.f;
    this->maxlives=5;
    this->lives=maxlives;

}

void Rabbit::initTexture()
{
if(!this->texture.loadFromFile("krolik.png"))
{
    std::cout<<"Error";
}
}

void Rabbit::initSprite()
{
this->sprite.setTexture(this->texture);
this->sprite.scale(0.15f,0.15f);
}

Rabbit::Rabbit()
{
    this->initVariables();
    this->initTexture();
    this->initSprite();
}

Rabbit::~Rabbit()
{

}

sf::FloatRect Rabbit::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

const int &Rabbit::getLives()
{
    return this->lives;
}

const int &Rabbit::getmaxLives()
{
    return this->maxlives;
}

void Rabbit::takelife(const int life )
{
  if(this->lives>0)
      this->lives-= life;
  if(this->lives <0)
      this->lives=0;
}

void Rabbit::givelife(const int health)
{
    if(this->lives <this->maxlives)
        this->lives+=health;
    if(this->lives>this->maxlives)
        this->lives=this->maxlives;
}

void Rabbit::move(const float dirX, const float dirY)
{
    this->sprite.move(this->speed*dirX,this->speed*dirY);

}

void Rabbit::bounds(const sf::RenderTarget& target)
{
    if (this->sprite.getGlobalBounds().left <= 0.f)
            this->sprite.setPosition(0.f, this->sprite.getGlobalBounds().top);

        if (this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= target.getSize().x)
            this->sprite.setPosition(target.getSize().x - this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().top);

        if (this->sprite.getGlobalBounds().top <= 0.f)
            this->sprite.setPosition(this->sprite.getGlobalBounds().left, 0.f);

        if (this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= target.getSize().y)
            this->sprite.setPosition(this->sprite.getGlobalBounds().left, target.getSize().y - this->sprite.getGlobalBounds().height);
}


void Rabbit::update(const sf::RenderTarget& target)
{
this->bounds(target);
}

void Rabbit::render(sf::RenderTarget& target)
{
target.draw(this->sprite);
}
