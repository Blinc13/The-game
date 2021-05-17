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

static const int   NumInGame           =16;
static const int   NumInWindow         =20;
static const float MaxBulletSpeed       =6;
static const int   MaxBlockDistance     =2;


class FunctionsToControl
{
private:
  static inline void math(sf::Vector2f &XY,const float MAX)
  {
    if (XY.x+XY.y==MAX){return;}

    float x=(XY.x+XY.y)/MAX;

    XY.x/=x;
    XY.y/=x;
  }

  static inline int substract(int x,const int y,const int r)
  {
    int h,k=(h=(x-y))-( (h>0)?r:-r );

    //cout<<k<<' '<<h<<endl;

    return x-k;
  }

  FunctionsToControl()
  {}

public:
  static inline int getMoveButton()
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){return 0;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){return 1;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){return 2;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){return 3;}


    return 4;
  }

  static inline sf::Vector2f getSpeedForBullet(const sf::Vector2i MouseCords,const sf::Vector2u windowSize)
  {
    bool k=false,i=false;

    sf::Vector2f BulletSpeed{float(MouseCords.x-int(windowSize.x)/2),float(MouseCords.y-int(windowSize.y)/2)};

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

  static inline sf::Vector2i getPointOnMapForMouse(sf::Vector2i Cords,const sf::Vector2u SizeOfWindow,sf::Vector2i point)
  {
    static bool k,j;

    Cords.x/=NumInWindow;
    Cords.y/=NumInWindow;

    Cords.x+=(point.x/=NumInGame)-(SizeOfWindow.x/2)/NumInWindow;
    Cords.y+=(point.y/=NumInGame)-(SizeOfWindow.y/2)/NumInWindow;

    if ((Cords.x-point.x > MaxBlockDistance) || (Cords.x-point.x < -MaxBlockDistance))
    {Cords.x=substract(Cords.x,point.x,MaxBlockDistance);}

    if ((Cords.y-point.y > MaxBlockDistance) || (Cords.y-point.y < -MaxBlockDistance))
    {Cords.y=substract(Cords.y,point.y,MaxBlockDistance);}

    //cout<<Cords.y-point.y<<endl;

    return Cords;
  }
};

///////////////////////////Main control////////////////////////////////////////
typedef FunctionsToControl func;
void controlHero(Hero &hero,std::vector<std::string> &map,sf::RenderWindow &window,Objects<Bullet> &BulletsV,float time)
{
  static float delay=0;

  //cout<<"1 "<<clock.getElapsedTime().asMicroseconds()<<endl;
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

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)&&delay>20.0F)
  {
    sf::Vector2f Speed=func::getSpeedForBullet(sf::Mouse::getPosition(window),window.getSize());
    delay=0.0F;

    hero.fire({Speed.x,Speed.y},BulletsV);
  }

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    if (hero.getRes()>0){
      sf::Vector2f heroCords=hero.getCords();
      sf::Vector2i cords=func::getPointOnMapForMouse(sf::Mouse::getPosition(window),window.getSize(),{int(heroCords.x),int(heroCords.y)});


      if (map[cords.y][cords.x]==' '){map[cords.y][cords.x]=(2+48);hero.subtractRes(1);}
    }
  }


  delay+=time;
  //cout<<"1.5 "<<clock.getElapsedTime().asMicroseconds()<<endl;
}
