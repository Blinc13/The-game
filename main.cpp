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
#include "MainControl.hpp"
#include "Game.hpp"
using namespace std;

int main()
{
  /*std::vector<std::string> SimbMap,BackgroundMap;
  loadMapFromTextFile("Maps/StandartMap/FrontMap.map",SimbMap," ");
  loadMapFromTextFile("Maps/StandartMap/BackMap.map",BackgroundMap,"0");
  sf::RenderWindow window(sf::VideoMode(600,300),"Test");
  Objects<Bullet> Bullets;
  Ui ui("Sprites/Ui/objects.png","Fonts/Ubuntu_Mono/UbuntuMono-Bold.ttf");
  window.setFramerateLimit(60);
  imageArea area={0,0,16,29};
  Hero hero("Sprites/Souls/Herous/character.png",area,{20*16,3*16},10);
  Objects<Enemy> persons;
  //persons.append(Enemy("Sprites/Ui/Center.png",{150,150,16,16},{2*16,4*16}));
  Cam View;
  sf::Clock Timer;
  Map map("Sprites/Objects/Overworld.png",BackgroundMap,SimbMap);
  float time;
  loadVecOfSpritesTexture("Maps/StandartMap/MapData.data",map.getVecOfTextures());

  for (int k=10;k<15;k++){persons.append(Enemy("Sprites/Souls/Enemies/Enemy.png",{0,0,48,50},{k*16,3*16}));}
  //cout<<SimbMapTest[3][3]<<endl;
  //for (int k=0;k<51;k++){cout<<SimbMapTest[k]<<endl;}
  sf::Image icon;
  icon.loadFromFile("Sprites/Ui/Icon.png");

  window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
  while (true){
    sf::Event event;
    time = (Timer.getElapsedTime().asMicroseconds())/8000.0F;
    Timer.restart();
    controlHero(hero,map.getFrontMap(),window,Bullets,time);
    map.drawMap(window);
    Bullets.Update(window,map.getFrontMap(),hero.getCords(),time);
    ui.drawUi(window,View,hero.getHealth(),hero.getAmmo()/10,hero.getRes());

    persons.Update(window,map.getFrontMap(),hero.getCords(),time);
    persons.Compire(Bullets);
    Damage(persons,hero);

    if (hero.getHealth()<=0)
    {
      hero.setPosition(5,30);

      hero.setHealth(100.0F);
    }
    //cout<<"2 "<<Timer.getElapsedTime().asMicroseconds()<<endl;
    //cout<<1<<endl;
    //cout<<2<<endl;
    if (window.pollEvent(event))
    {
      if (event.type==sf::Event::Closed){window.close();break;}
    }
    //cout<<3<<endl;
    View.setPosition(hero.getCords());
    window.setView(View.getCamForDrav());
    //cout<<4<<endl;
    window.draw(hero.Sprite());
    window.display();
    window.clear();
  }*/
  Game game;

  game.drawMenu();

  return 0;
}
