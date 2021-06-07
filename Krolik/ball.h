#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
enum Balltype{NEUTRAL=0,DAMAGING,HEALING,NUMBER} ;
class Ball
{
private:
    sf::CircleShape ball;
    int type;
public:
Ball(sf::RenderWindow& window,int type);
virtual ~Ball();
const sf::FloatRect getBounds() const;
const int& getType() ;
void initBall(sf::RenderWindow& window);
void update();
void render(sf::RenderTarget& target);
};

#endif // BALL_H
