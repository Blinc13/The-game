///////////////////////////////By Blinc13//////////////////////

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "View.hpp"
#include "Souls.hpp"
#include "Game.hpp"
#include "Physics.hpp"
#include "Control.hpp"
using namespace std;


int main()
{
  sf::RenderWindow window(sf::VideoMode(600,400),"Test");
  window.setFramerateLimit(60);
  imageArea area={0,0,16,29};
  Hero hero("Sprites/Souls/Herous/character.png",area,sf::Vector2f(30,30),10);
  Cam View;
  sf::Clock Timer;
  Map map("Sprites/Objects/Overworld.png",BackgroundMap,SimbMapTest);
  float time;
  //cout<<SimbMapTest[3][3]<<endl;
  for (int k=0;k<6;k++){cout<<SimbMapTest[k]<<endl;}

  while (true){
    sf::Event event;
    time = (Timer.getElapsedTime().asMicroseconds())/8000.0F;
    Timer.restart();
    controlHero(hero,map,time);
    //cout<<1<<endl;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
      hero.setPosition(0,0);
    }
    //cout<<2<<endl;
    if (window.pollEvent(event))
    {
      if (event.type==sf::Event::Closed){window.close();break;}
    }
    //cout<<3<<endl;
    View.setCamOnObj(hero);
    window.setView(View.getCamForDrav());
    map.drawMap(window);
    //cout<<4<<endl;
    window.draw(hero.Sprite());
    window.display();
    window.clear();
  }
  return 0;
}
