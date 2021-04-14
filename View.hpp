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

  void setposition(float x,float y)
  {Camera.setCenter(x,y);}

  void setRotation(float x)
  {Camera.setRotation(x);}
///////////////////////get/////////////////////////
  sf::View getCamForDrav()
  {return Camera;}

///////////////////////constructors////////////////

  Cam()
  {
    Camera.setSize(sf::Vector2f(100,50));
    Camera.zoom(5);
  }
};
