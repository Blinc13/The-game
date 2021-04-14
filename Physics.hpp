#pragma once
#include <math.h>
using namespace std;

void Colision(Hero &hero,Map &map,float time)
{
  sf::Vector2f C=hero.getCords();

  C.y/=15.0F;
  C.x/=15.0F;

  //std::cout<<int(C.y)<<std::endl
  //<<int(C.x)<<std::endl;

  if (SimbMapTest[int(C.y)][int(C.x-1)]!=' '&&(C.x-trunc(C.x))<0.9991F/time){hero.blockSide(2,false);}
  if (SimbMapTest[int(C.y-1)][int(C.x)]!=' '&&(C.y-trunc(C.y))<0.9991F/time){hero.blockSide(0,false);}
  if (SimbMapTest[int(C.y+1)][int(C.x)]!=' '&&(C.y-trunc(C.y))>0.9991F/time){hero.blockSide(1,false);}
  if (SimbMapTest[int(C.y)][int(C.x+1)]!=' '&&(C.x-trunc(C.x))>0.9991f/time){hero.blockSide(3,false);}
}
