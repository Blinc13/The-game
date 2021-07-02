
//////////////////////////////By Blinc13////////////////////////////
//////////////////////////////Test//////////////////////////////////
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Map.hpp"
#include "Souls.hpp"
#include "View.hpp"
#include "Funcs.hpp"
#include "Physics.hpp"
#include "Objects.hpp"
//#include <thread>
//#include <chrono>

struct EngineTime
{
  float time;
  sf::Clock *Timer;
};


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
  EngineTime EngineParams;

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
    void init(const std::string HeroTextureFileDirectory,const imageArea HeroTextureArea,const std::string MapDataFilesDirectory)
    {
      std::vector<std::string> FrontMap,BackMap;

      hero=new Hero(HeroTextureFileDirectory,HeroTextureArea,{20.0F*16.0F,3.0F*16.0F},10);
      ui=new Ui("Sprites/Ui/objects.png","Fonts/Ubuntu_Mono/UbuntuMono-Bold.ttf");

      loadMapFromTextFile(MapDataFilesDirectory+"/FrontMap.map",FrontMap," ");
      loadMapFromTextFile(MapDataFilesDirectory+"/BackMap.map" ,BackMap ,"0");
      map=new Map("Sprites/Objects/Overworld.png",BackMap,FrontMap);
      loadVecOfSpritesTexture(MapDataFilesDirectory+"/MapData.data",map->getVecOfTextures());

      Enemys=new Objects<Enemy>();
      for (int k=0;k<10;k++)
        Enemys->append(new Enemy("Sprites/Souls/Enemies/Enemy.png",{0,0,48,50},{2*16,2*16}));
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
            RunGame();
            break;
          case 1:
            setServer();
            break;
        }

        if (ActionsOfWindow()){return;}

        window->display();
        window->clear();
      }
    }

    void RunGame()
    {
      EngineParams.time=0;
      EngineParams.Timer=new sf::Clock();

      while (true)
      {
        EngineParams.time = (EngineParams.Timer->getElapsedTime().asMicroseconds())/8000.0F;
        EngineParams.Timer->restart();
        controlHero(hero,map->getFrontMap(),window,Bullets,EngineParams.time);
        map->drawMap(*window);
        Bullets->Update(window,map->getFrontMap(),hero->getCords(),EngineParams.time);
        ui->drawUi(window,Camera,hero->getHealth(),hero->getAmmo()/10,hero->getRes());

        Enemys->Update(window,map->getFrontMap(),hero->getCords(),EngineParams.time);
        Enemys->Compire(*Bullets);
       Damage(*Enemys,hero);

        if (hero->getHealth()<=0)
        {
          hero->setPosition(5,30);

          hero->setHealth(100.0F);
        }

        if (ActionsOfWindow()){break;}

        Camera->setPosition(hero->getCords());
        window->setView(Camera->getCamForDrav());

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
