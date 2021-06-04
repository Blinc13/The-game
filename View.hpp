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
  void setZoom(float x)
  {Camera.zoom(x);}

  void setPosition(const sf::Vector2f &Cords)
  {Camera.setCenter(Cords);}

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
