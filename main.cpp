///////////////////////////////By Blinc13//////////////////////

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "View.hpp"
#include "Physics.hpp"
#include "Souls.hpp"
#include "Control.hpp"
#include "Game.hpp"
using namespace std;


int main()
{
  sf::RenderWindow window(sf::VideoMode(300,200),"Test");
  sf::CircleShape shape(10);
  imageArea area={398,264,35,59};
  Hero hero("Sprites/Souls/Herous/ModularActor4_3.png",area,sf::Vector2f(30,35),10);
  Cam View;
  Map map("Sprites/Objects/tilemaps_forest01_1.png");

  while (true){
    sf::Event event;
    controlHero(hero);
    View.setCamOnObj(hero);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
      hero.setPosition(0,0);
    }

    if (window.pollEvent(event))
    {
      if (event.type==sf::Event::Closed){window.close();break;}
    }

    window.setView(View.getCamForDrav());
    window.draw(shape);
    window.draw(hero.Sprite());
    map.drawMap(window);
    window.display();
    window.clear();
  }
  return 0;
}
