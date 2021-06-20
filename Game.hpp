
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
  Cam *Camera;
  Menu *menu;
  Ui *ui;
  Objects<Enemy> *Enemys;
  Objects<Bullet>   *Bullets;

  bool isServer=true;

  void setServer()
  {isServer=!isServer;}

  inline bool ActionsOfWindow()
  {
    static sf::Event event;
    if (window->pollEvent(event))
    {
      if (event.type==sf::Event::Closed){window->close();return true;}
    }

    return false;
  }
public:
    void init(const std::string HeroTextureFileDirectory,const imageArea HeroTextureArea,const std::string MapTextureFileDirectory,const std::string MapDataFilesDirectory)
    {
      std::vector<std::string> FrontMap,BackMap;

      hero=new Hero(HeroTextureFileDirectory,HeroTextureArea,{20*16,3*16},10);
      ui=new Ui("Sprites/Ui/objects.png","Fonts/Ubuntu_Mono/UbuntuMono-Bold.ttf");

      loadMapFromTextFile(MapTextureFileDirectory+"/FrontMap.map",FrontMap," ");
      loadMapFromTextFile(MapTextureFileDirectory+"/BackMap.map" ,BackMap ,"0");
      map=new Map("Sprites/Objects/Overworld.png",BackMap,FrontMap);

      Enemys=new Objects<Enemy>();
      Bullets=new     Objects<Bullet>();

      window->setFramerateLimit(60);
    }

    void drawMenu()
    {
      bool Update=true;

      while (Update){
        switch (menu->draw())
        {
          case 0:
            Update=false;
            break;
          case 1:
            setServer();
            break;
        }

        window->display();
        window->clear();
      }
    }

    void RunGame()
    {
      while (true)
      {
        float time = (Timer.getElapsedTime().asMicroseconds())/8000.0F;
        Timer.restart();
        controlHero(hero,map->getFrontMap(),window,Bullets,time);
        map->drawMap(window);
        Bullets->Update(window,map->getFrontMap(),hero.getCords(),time);
        ui->drawUi(window,View,hero->getHealth(),hero->getAmmo()/10,hero->getRes());

        Enemys->Update(window,map->getFrontMap(),hero->getCords(),time);
        Enemys->Compire(Bullets);
        Damage(Enemys,hero);

        if (hero->getHealth()<=0)
        {
          hero->setPosition(5,30);

          hero->setHealth(100.0F);
        }

        ActionsOfWindow();

        Camera->setPosition(hero->getCords());
        window->setView(View->getCamForDrav());

        window->draw(hero->Sprite());
        window->display();
        window->clear();
      }
    }

  Game()
  {
    sf::Image icon;icon.loadFromFile("Sprites/Ui/Icon.png");
    window=new sf::RenderWindow(sf::VideoMode(600,300),"The game");
    window->setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
    Camera=new Cam();

    menu=loadMenuFromFile("Conf/Menu.conf",window);
  }

  ~Game()
  {
  }
};
