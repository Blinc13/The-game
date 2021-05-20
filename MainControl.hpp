#pragma once
#include "ControlFunctions.hpp"
using namespace std;


typedef FunctionsToControl func;
void controlHero(Hero &hero,std::vector<std::string> &map,sf::RenderWindow &window,Objects<Bullet> &BulletsV,float time)
{
  static float FireDelay=0,BlockDelay=0;

  sf::Vector2i MousePosition=sf::Mouse::getPosition(window);

  Colision(hero,map,time);

  switch (func::getMoveButton())
  {
    case 0:
      if (hero.getBlockSide(0)){hero.move(0,-1.0F*time,2,time);}
      break;
    case 1:
      if (hero.getBlockSide(1)){hero.move(0,1.0F*time,0,time);}
      break;
    case 2:
      if (hero.getBlockSide(2)){hero.move(-1.0F*time,0,3,time);}
      break;
    case 3:
      if (hero.getBlockSide(3)){hero.move(1.0F*time,0,1,time);}
      break;
  }
  hero.resetBlockSides();



  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){hero.appendAmmo(1);}

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)&&FireDelay>DelayBetweenShots)
  {
    sf::Vector2f Speed=func::getSpeedForBullet(sf::Mouse::getPosition(window),window.getSize());
    FireDelay=0.0F;

    hero.fire({Speed.x,Speed.y},BulletsV);
  }

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && BlockDelay>DelayInBlockInstallation &&
     (MousePosition.x<=window.getSize().x && MousePosition.y<=window.getSize().y))
  {
    if (hero.getRes()>0){
      sf::Vector2f heroCords=hero.getCords();
      sf::Vector2i cords=func::getPointOnMapForMouse(sf::Mouse::getPosition(window),window.getSize(),{int(heroCords.x),int(heroCords.y)},MaxBlockDistance);


      if (map[cords.y][cords.x]==' '){map[cords.y][cords.x]=(2+48);hero.subtractRes(1);BlockDelay=0.0F;}
    }
  }


  FireDelay+=time;
  BlockDelay+=time;
}
