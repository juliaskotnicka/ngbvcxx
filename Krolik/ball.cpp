#include "ball.h"
#include <SFML/Graphics.hpp>


Ball::~Ball()
{


}

const sf::FloatRect Ball::getBounds() const
{
    return this->ball.getGlobalBounds();
}

const int &Ball::getType()
{
    return this->type;
}

void Ball::initBall(sf::RenderWindow& window)
{
    this->ball.setRadius(static_cast<float>(rand()%10+10));
    sf::Color color;
    switch(this->type)
    {
    case NEUTRAL:
        color=sf::Color(rand()%255+1,rand()%255+1,rand()%255+1);
        break;
    case DAMAGING:
        color=sf::Color::Black;
        this->ball.setOutlineColor(sf::Color::Red);
        this->ball.setOutlineThickness(3.f);
        break;
    case HEALING:
        color=sf::Color::Blue;
        this->ball.setOutlineColor(sf::Color::Blue);
        this->ball.setOutlineThickness(3.f);
        break;
    }

    this->ball.setFillColor(color);
    this->ball.setPosition(
                sf::Vector2f(
                    static_cast<float>(rand()% window.getSize().x - this->ball.getGlobalBounds().width),
                    static_cast<float>(rand()% window.getSize().y - this->ball.getGlobalBounds().height)));

}
Ball::Ball(sf::RenderWindow& window,int type):type(type)
{
    this->initBall(window);
    this->type =type;

}

void Ball::update()
{

}

void Ball::render(sf::RenderTarget &target)
{
    target.draw(this->ball);
}
