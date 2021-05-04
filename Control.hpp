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

const float MaxBulletSpeed=6;

inline void math(sf::Vector2f &XY)
{
  if (XY.x+XY.y==6){return;}

  float x=(XY.x+XY.y)/6.0F;

  XY.x/=x;
  XY.y/=x;
}

static inline int getMoveButton()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){return 0;}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){return 1;}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){return 2;}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){return 3;}
  return 4;
}

inline sf::Vector2f getSpeedForBullet(const sf::RenderWindow &Window)
{
  bool k=false,i=false;
  sf::Vector2i MouseCords=sf::Mouse::getPosition(Window);

  sf::Vector2f BulletSpeed{float(MouseCords.x-=300),float(MouseCords.y-150)};

  float x=BulletSpeed.x,y=BulletSpeed.y;

  if (x<0){x*=-1;k=true;}
  if (y<0){y*=-1;i=true;}

  BulletSpeed.x=x/y;
  BulletSpeed.y=y/x;

  math(BulletSpeed);

  if (k){BulletSpeed.x*=-1;}
  if (i){BulletSpeed.y*=-1;}

  return BulletSpeed;
}

///////////////////////////Main control////////////////////////////////////////
void controlHero(Hero &hero,std::vector<std::string> &map,sf::RenderWindow &window,Objects &Bullets,float time)
{
  static float delay=0;

  //cout<<"1 "<<clock.getElapsedTime().asMicroseconds()<<endl;
  Colision(hero,map,time);
  //cout<<1<<endl;
  switch (getMoveButton())
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
  //cout<<1<<endl;
  hero.resetBlockSides();

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){hero.appendAmmo(1);}

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)&&delay>20.0F)
  {
    sf::Vector2f Speed=getSpeedForBullet(window);

    delay=0.0F;

    hero.fire({Speed.x,Speed.y},Bullets);
  }

  delay+=time;

  //cout<<"1.5 "<<clock.getElapsedTime().asMicroseconds()<<endl;
}
