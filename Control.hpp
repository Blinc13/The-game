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

inline void math(sf::Vector2f &XY,const float MAX)
{
  if (XY.x+XY.y==MAX){return;}

  float x=(XY.x+XY.y)/MAX;

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

inline sf::Vector2f getSpeedForBullet(const sf::Vector2i MouseCords,const sf::Vector2u windowSize)
{
  bool k=false,i=false;
  //cout<<MouseCords.x<<' '<<MouseCords.y<<endl;
  //cout<<windowSize.x<<' '<<windowSize.y<<endl;
  sf::Vector2f BulletSpeed{float(MouseCords.x-int(windowSize.x)/2),float(MouseCords.y-int(windowSize.y)/2)};
  //cout<<BulletSpeed.x<<' '<<BulletSpeed.y<<endl;
  float x=BulletSpeed.x,y=BulletSpeed.y;

  if (x<0){x*=-1;k=true;}
  if (y<0){y*=-1;i=true;}

  BulletSpeed.x=x/y;
  BulletSpeed.y=y/x;

  math(BulletSpeed,6);

  if (k){BulletSpeed.x*=-1;}
  if (i){BulletSpeed.y*=-1;}

  return BulletSpeed;
}

///////////////////////////Main control////////////////////////////////////////
void controlHero(Hero &hero,std::vector<std::string> &map,sf::RenderWindow &window,Objects<Bullet> &BulletsV,float time)
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
    sf::Vector2f Speed=getSpeedForBullet(sf::Mouse::getPosition(window),window.getSize());

    delay=0.0F;

    hero.fire({Speed.x,Speed.y},BulletsV);
  }

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    sf::Vector2u size=window.getSize();
    sf::Vector2i cords=sf::Mouse::getPosition(window);
    sf::Vector2f heroCords=hero.getCords();

    cords={(cords.x-size.x/2)/16,(cords.y-size.y/2)/16};

    cords.x+=int(heroCords.x/16);
    cords.y+=int(heroCords.y/16);

    map[cords.y][cords.x]=(-16+48);
  }
  delay+=time;

  //cout<<"1.5 "<<clock.getElapsedTime().asMicroseconds()<<endl;
}
