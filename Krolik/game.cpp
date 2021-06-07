#include "rabbit.h"
#include "game.h"

#include <SFML/Graphics.hpp>
 #include <windows.h>

void Game::initVariables()
{
    this->endGame=false;
    this->maxtime=10.f;
    this->time=this->maxtime;
    this->maxball=5 ;
    this->points =0;
}
void Game::initRabbit()
{
    this-> rabbit = new Rabbit();
}

void Game::initFont()
{
    if(!this->font.loadFromFile("PixellettersFull.ttf"))
    {
        std::cout<<"Font error"<<std::endl;
    }
}

void Game::initText()
{
this->text.setFont(this->font);
    this->text.setFillColor(sf::Color::Black);
    this->text.setCharacterSize(40);
    this->text.setPosition(650,10);

    this->endText.setFont(this->font);
    this->endText.setFillColor(sf::Color::Black);
    this->endText.setCharacterSize(70);
    this->endText.setPosition(100,200);
    this->endText.setString("You poisoned the rabbit ;( ");
}



void Game::initBackground()
{
    if (!this->backgroundTexture.loadFromFile("grass6.jpg"))
    {
        std::cout << "error background" << "\n";
    }

    this->background.setTexture(this->backgroundTexture);
}

void Game::initMusic()
{
    if (!this->music.openFromFile("sound.wav"))
    {
        std::cout << "music error" << "\n";
    }
    music.play();

}


Game::Game()
{
 this->initVariables();

    this->initBackground();
    this->initRabbit();
    this->initFont();
    this->initText();
    this->initMusic();

}

Game::~Game()
{

    delete this->rabbit;

}

const bool &Game::GameEnd()
{
   return this-> endGame;
}

const bool Game::open(sf::RenderWindow& window) const
{
    return window.isOpen();
}


void Game::pollEvents(sf::RenderWindow& window)
{
    while(window.pollEvent(this->event))
    {
        if(this->event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::createball(sf::RenderWindow& window)
{
     if(this->time < this->maxtime)
         this->time+=1.f;
     else

        {
         if(this->balls.size() <this->maxball)
         {
             this->balls.push_back(Ball(window, this->randomize()));
             this->time=0.f;
         }
     }

}

void Game::updateRabbit(sf::RenderWindow& window)
{
  this->rabbit->update(window);
    if (this->rabbit->getLives() <=0 )
        this->endGame = true;

}

 int Game::randomize()
{
    int type=Balltype::NEUTRAL;
    int randcolor= rand() %100+1;
    if(randcolor> 60 && randcolor <=80)
        type= Balltype::DAMAGING;
    else if(randcolor > 70 && randcolor <=100)
          type=Balltype::HEALING;

return type;
}

void Game::remove()
{
   for(size_t i=0; i<balls.size();i++)
   {
   if(this->rabbit->getBounds().intersects(this->balls[i].getBounds()))
   {
   switch(this->balls[i].getType())
   {
       case Balltype::NEUTRAL:
             this->points++;
           break;
       case Balltype::DAMAGING:
           this->rabbit->takelife(1);
       break;
   case Balltype::HEALING:
       this->rabbit->givelife(1);
       break;
   }
         this->balls.erase(this->balls.begin()+i);
   }
   }
}

void Game::moving()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->rabbit->move(-1.f,0.f);

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
       this->rabbit->move(1.f,0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->rabbit->move(0.f,-1.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->rabbit->move(0.f,1.f);
    }
}

void Game::renderBackground(sf::RenderWindow &window)
{
    window.draw(this->background);
}

void Game::rendertext(sf::RenderTarget& target)
{
    target.draw(this->text) ;
}

void Game::updatePoints()
{
  std:: stringstream ss;
  ss <<"Points: "<< this->points<<std::endl<<"Lives: "<<this->rabbit->getLives()<<"/"<<this->rabbit->getmaxLives()<<std::endl;
  this->text.setString(ss.str());

}



void Game::update(sf::RenderWindow &window)
{
this->pollEvents(window);
this->updateRabbit(window);
if(rabbit->getLives() >0)
{
this->moving();
this->createball(window);
this->remove();
this->initBackground();
this->updatePoints();
}

;}
void Game::render(sf::RenderWindow &window)
{
window.clear(sf::Color::Blue);
    this->renderBackground(window);
this->rabbit->render(window);
    for (auto i:this->balls)
    {
        i.render(window);
    }
     this->rendertext(window);
if(this->endGame==true)
{
window.draw(this->endText);

}

window.display();

}
