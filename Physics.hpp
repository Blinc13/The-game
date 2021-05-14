#pragma once
#include <math.h>
using namespace std;

template<class H>
void Colision(H &Obj,std::vector<std::string> &Map,const float time);

template<class X>
class Objects
{
private:
  typename std::vector<X*> objects;
  typename std::vector<X*>::iterator iter;

public:
  void Update(sf::RenderWindow &Window,std::vector<std::string> &map,const sf::Vector2f point,const float time)
  {
    for (int k=0;k<objects.size()-1;k++)
    {
      if (objects[k]==NULL){continue;}

      Colision(*objects[k],map,time);
      Window.draw(objects[k]->draw());
      objects[k]->Update(point,map,time);

      if (objects[k]->Remove){delete objects[k];objects[k]=NULL;}
    }
  }

  template<class Y>
  void Compire(Objects<Y> &CompireObjects)
  {
    for (int k=0;k<80;k++)
    {
      if (objects[k]==NULL){continue;}

      for (int j=0;j<80;j++)
      {
        if (CompireObjects[j]==NULL){continue;}

        if (trunc(objects[k]->getCords().x/16)==trunc(CompireObjects[j]->getCords().x/16) && trunc(objects[k]->getCords().y/16)==trunc(CompireObjects[j]->getCords().y/16))
        {
          objects[k]->Remove=true;
          CompireObjects[j]->Remove=true;

          continue;
        }
      }
    }
  }

  void append(X object)
  {
    if (iter==objects.end()){iter=objects.begin();}
    delete *iter;
    *iter=new X(object);
    iter++;
  }


  X* operator [](int k) const
  {return objects[k];}


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

template<class x,class y>
void Damage(Objects<x> &Enemys,y& hero)
{
  const sf::Vector2f HeroPosition={trunc(hero.getCords().x/16),trunc(hero.getCords().y/16)};
  for (int k=0;k<80;k++)
  {
    if (Enemys[k]==NULL){continue;}

    if (trunc(Enemys[k]->getCords().x/16)==HeroPosition.x && trunc(Enemys[k]->getCords().y/16)==HeroPosition.y){hero.DamageSoul(0.1F);}
  }
}
