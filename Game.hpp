
//////////////////////////////By Blinc13////////////////////////////
//////////////////////////////Test//////////////////////////////////
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Map.hpp"
#include "Souls.hpp"
#include "View.hpp"
//#include <thread>
//#include <chrono>




class Game
{
private:
  Hero *hero;
  Map *map;
  sf::RenderWindow *window;
  View *Camera;
  Menu *menu;
  Objects<Enemy> *Enemys;

  bool isServer;

  void setServer()
  {isServer=!isServer;}
public:
  Game()
  {
    sf::Image icon;icon.loadFromFile("Sprites/Ui/Icon.png");
    window=new sf::RenderWindow(sf::VideoMode(600,300),"The game");
    window->setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());

    menu=loadMenuFromFile("Conf/Menu.conf",window);

    while (true)
    {
      if (menu->draw()>0){break;}

      window->display();
      window->clear();
    }
  }

  ~Game()
  {
  }
};
