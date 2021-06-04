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

static const int   NumInGame                   =16   ;
static const int   NumInWindow                 =20   ;
static const int   MaxBlockDistance            =2    ;
static const float MaxBulletSpeed              =6.0F ;
static const float DelayBetweenShots           =25.0F;
static const float DelayInBlockInstallation    =30.0F;


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

  static inline sf::Vector2i getPointOnMapForMouse(sf::Vector2i Cords,const sf::Vector2u SizeOfWindow,sf::Vector2i point,bool Limitation=false,const int Max=MaxBlockDistance)
  {
    static bool k,j;

    Cords.x/=NumInWindow;
    Cords.y/=NumInWindow;

    Cords.x+=(point.x/=NumInGame)-(SizeOfWindow.x/2)/NumInWindow;
    Cords.y+=(point.y/=NumInGame)-(SizeOfWindow.y/2)/NumInWindow;

    if (Limitation){
      if ((Cords.x-point.x > Max) || (Cords.x-point.x < -Max))
      {Cords.x=substract(Cords.x,point.x,MaxBlockDistance);}

      if ((Cords.y-point.y > Max) || (Cords.y-point.y < -Max))
      {Cords.y=substract(Cords.y,point.y,MaxBlockDistance);}
    }
    //cout<<Cords.x<<' '<<Cords.y<<endl;

    return Cords;
  }
};
