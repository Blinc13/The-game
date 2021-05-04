///////////////////////////////By Blinc13//////////////////////

#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>

#include "Funcs.hpp"
#include "View.hpp"
#include "Map.hpp"
#include "Objects.hpp"
#include "Physics.hpp"
#include "Souls.hpp"
#include "Ui.hpp"
#include "Control.hpp"
#include "Game.hpp"
using namespace std;

int main()
{
  loadMapFromTextFile("Maps/StandartMap/FrontMap.map",SimbMapTest);
  loadMapFromTextFile("Maps/StandartMap/BackMap.map",BackgroundMapTest);
  sf::RenderWindow window(sf::VideoMode(600,300),"Test");
  Objects Bullets;
  Ui ui("Sprites/Ui/objects.png","Fonts/Ubuntu_Mono/UbuntuMono-Bold.ttf");
  window.setFramerateLimit(60);
  imageArea area={0,0,16,29};
  Hero hero("Sprites/Souls/Herous/character.png",area,sf::Vector2f(30,30),10);
  Enemy person("Sprites/Ui/Center.png",{150,150,16,16},{6*16,2*16});
  Cam View;
  sf::Clock Timer;
  Map map("Sprites/Objects/Overworld.png",BackgroundMapTest,SimbMapTest);
  float time;
  //cout<<SimbMapTest[3][3]<<endl;
  for (int k=0;k<6;k++){cout<<SimbMapTest[k]<<endl;}

  while (true){
    sf::Event event;
    time = (Timer.getElapsedTime().asMicroseconds())/8000.0F;
    Timer.restart();
    controlHero(hero,map.getFrontMap(),window,Bullets,time);
    map.drawMap(window);
    Bullets.Update(window,map.getFrontMap(),time);
    ui.drawUi(window,View,hero.getHealth(),hero.getAmmo()/10);
    Colision(person,map.getFrontMap(),time);
    person.treatmentII(hero.getCords());
    person.move();
    //cout<<"2 "<<Timer.getElapsedTime().asMicroseconds()<<endl;
    //cout<<1<<endl;
    //cout<<2<<endl;
    if (window.pollEvent(event))
    {
      if (event.type==sf::Event::Closed){window.close();break;}
    }
    //cout<<3<<endl;
    View.setCamOnObj(hero);
    window.setView(View.getCamForDrav());
    //cout<<4<<endl;
    window.draw(hero.Sprite());
    window.draw(person.draw());
    window.display();
    window.clear();
  }
  return 0;
}
