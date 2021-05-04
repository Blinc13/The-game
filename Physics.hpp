#pragma once
#include <math.h>
using namespace std;

template<class H>
void Colision(H &Obj,std::vector<std::string> &Map,const float time);

class Objects
{
private:
  std::vector<Bullet*> objects;
  std::vector<Bullet*>::iterator iter;

public:
  void Update(sf::RenderWindow &Window,std::vector<std::string> &map,float time)
  {
    for (int k=0;k<objects.size()-1;k++)
    {
      if (objects[k]==NULL){continue;}

      objects[k]->update();
      Window.draw(objects[k]->draw());
      Colision(*objects[k],map,time);

      if (objects[k]->Remove){delete objects[k];objects[k]=NULL;}
    }
  }

  void append(Bullet bullet)
  {
    if (iter==objects.end()){iter=objects.begin();}
    delete *iter;
    *iter=new Bullet(bullet);
    iter++;
  }


  Objects():objects(80),iter(objects.begin())
  {}

  ~Objects()
  {
    for (int k=0;k<objects.size();k++)
    {
      if (objects[k]==NULL){continue;}

      delete objects[k];
    }
  }
};

template<class H>
void Colision(H &Obj,std::vector<std::string> &Map,const float time)
{
  sf::Vector2f CordsFloat=Obj.getCords();
  sf::Vector2<int> C={int(CordsFloat.x),int(CordsFloat.y)};


  CordsFloat.x/=16.0F;
  CordsFloat.y/=16.0F;

  C.y/=16;
  C.x/=16;

  //std::cout<<int(C.y)<<std::endl
  //<<int(C.x)<<std::endl;

  if (Map[C.y][C.x-1]!=' '&&(CordsFloat.x-trunc(CordsFloat.x))<0.9991F/time){Obj.blockSide(2,false);}
  if (Map[C.y-1][C.x]!=' '&&(CordsFloat.y-trunc(CordsFloat.y))<0.9991F/time){Obj.blockSide(0,false);}
  if (Map[C.y+1][C.x]!=' '&&(CordsFloat.y-trunc(CordsFloat.y))>0.9991F/time){Obj.blockSide(1,false);}
  if (Map[C.y][C.x+1]!=' '&&(CordsFloat.x-trunc(CordsFloat.x))>0.9991f/time){Obj.blockSide(3,false);}
}
