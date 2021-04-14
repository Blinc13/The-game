////////////////////////By Blinc13////////////////////////////
////////////////////////Help//////////////////////////////////

/*drivingSides
{
  Up      = 0,
  Down    = 1,
  Left    = 2,
  Right   = 3,
}*/

/////////////////////////CODE/////////////////////////////////
//////////////////////////////////////////////////////////////

#pragma once
using namespace std;
int getMoveButtons()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){return 0;}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){return 1;}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){return 2;}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){return 3;}
  return 4;
}




///////////////////////////Main control////////////////////////////////////////
void controlHero(Hero &hero,Map &map,float time)
{
  Colision(hero,map,time);
  //cout<<1<<endl;
  switch (getMoveButtons())
  {
    case 0:
      if (hero.getBlockSide(0)){hero.move(0,-1.0F*time,0,time);}
      break;
    case 1:
      if (hero.getBlockSide(1)){hero.move(0,1.0F*time,1,time);}
      break;
    case 2:
      if (hero.getBlockSide(2)){hero.move(-1.0F*time,0,2,time);}
      break;
    case 3:
      if (hero.getBlockSide(3)){hero.move(1.0F*time,0,3,time);}
      break;
  }
  //cout<<1<<endl;
  hero.resetBlockSides();
}
