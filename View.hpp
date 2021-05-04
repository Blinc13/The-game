#pragma once
#include <math.h>

struct imageArea
{
  int x,y;

  int Width,Heigth;
};




class Cam
{
private:
  sf::View Camera;

protected:
  float Width,Heigth;

public:
///////////////////////set/////////////////////////
  template<class x>
  void setCamOnObj(const x &Obj)
  {
    sf::Vector2f Centr=Obj.getCords();
    Camera.setCenter(trunc(Centr.x),trunc(Centr.y));
  }

  void setZoom(float x)
  {Camera.zoom(x);}

  void setPosition(const float x,const float y)
  {Camera.setCenter(x,y);}

  void setPosition(const sf::Vector2<int> Cords)
  {Camera.setCenter(Cords.x,Cords.y);}

  void setRotation(float x)
  {Camera.setRotation(x);}
///////////////////////get/////////////////////////
  sf::Vector2f getPosition()        const
  {return Camera.getCenter();}

  sf::View &getCamForDrav()
  {return Camera;}

///////////////////////constructors////////////////

  Cam(float x=100,float y=50)
  {
    Camera.setSize(sf::Vector2f(x,y));
    Camera.zoom(5);

    Width=x;
    Heigth=y;
  }
};
