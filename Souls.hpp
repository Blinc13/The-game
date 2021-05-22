/////////////////////////////By Blinc13////////////////////////////

/////////////////////////////Help//////////////////////////////////

/*drivingSides
{
  Up      = 0,
  Down    = 1,
  Left    = 2,
  Right   = 3,
}*/



/////////////////////////////CODE//////////////////////////////////
///////////////////////////////////////////////////////////////////


#pragma once
#include <vector>
#include <string>
#include <math.h>


enum Act
{
  move    = 0,
  attack  = 1,
};



class Soul
{
private:
                        //Animation//
  float AnStage;

protected:
  float Health,Damage;
  bool UnlockSides[4]={1,1,1,1};


  imageArea TextureArea;
  sf::Texture BodyTexture;
  sf::Sprite Body;



  void AnimationFunc(const int Side,const float Time)
  {
    TextureArea.y=Side*32;

    Body.setTextureRect(sf::IntRect(TextureArea.Width*int(AnStage),TextureArea.y,
                                    TextureArea.Width,TextureArea.Heigth));

    if (AnStage>=4.0F){AnStage=0;}


    AnStage+=Time/20;
  }
public:
                            //Set//

  void blockSide(int Position,bool x)
  {UnlockSides[Position]=x;}

  void resetBlockSides()
  {
    for (int k=0;k<4;k++)
        UnlockSides[k]=true;
  }

  void setHealth(float H)
  {Health=H;}

  //Return soul death (false/true)
  bool DamageSoul(const float DamageF)
  {
    Health-=DamageF;

    if (Health<=0){return true;}

    return false;
  }

/////////////////////////Get//////////////////////////////
  float getHealth()
  {return Health;}

  bool getBlockSide(int Position)
  {return UnlockSides[Position];}

  Soul(std::string FileDirectory,const imageArea &Area,float D,float H):TextureArea(Area),AnStage(0),Damage(D),Health(H)
  {
    BodyTexture.loadFromFile(FileDirectory);

    Body.setTexture(BodyTexture);
    Body.setTextureRect(sf::IntRect(Area.x,Area.y,
      Area.Width,Area.Heigth));
  }

};




class Hero: /*The endow with soul*/public Soul
{
protected:
  float SpeedX,SpeedY,MaxSpeed;
  int Amunition,Resources=100;

public:
                            //Set//

  void move(const float x,const float y,const int Side,const float &Time)
  {
    Body.move(x,y);
    AnimationFunc(Side,Time);
  }

                            //For future//
  void fire(sf::Vector2f speed,Objects<Bullet> &obj)
  {
    if (Amunition<=0){return;}
    obj.append(Bullet("Sprites/Ui/Center.png",{300,300,4,4},getCords(),{speed.x,speed.y}));

    subtractAmmo(1);
  }

  inline void setPosition(const int x,const int y)
  {Body.setPosition(x*16,y*16);}

  inline void setAmmo(const int x)
  {Amunition=x;}

  inline void appendAmmo(const int x)
  {Amunition+=x;}

  inline void subtractAmmo(const int x)
  {Amunition-=x;}

  inline void appendRes(const int k)
  {Resources+=k;}

  inline void subtractRes(const int k)
  {Resources-=k;}
                    //Get//
  inline sf::Vector2f getCords() const
  {return Body.getPosition();}

  inline int getAmmo()           const
  {return Amunition;}

  inline int getRes()            const
  {return Resources;}

  inline sf::Sprite Sprite()     const
  {return Body;}


  Hero(std::string FileDirectory,imageArea Area,sf::Vector2f Cords,float MaxSpeedInput):
  Soul(FileDirectory,Area,25,100),Amunition(100)
  {
    Body.setPosition(Cords.x,Cords.y);
    Body.setOrigin(Area.Width/2,(Area.Heigth/4)*3);
    SpeedX=0;
    SpeedY=0;
    MaxSpeed=MaxSpeedInput;
  }
};





class Enemy:public Soul
{
private:
  mutable sf::Vector2f XYSpeed;
  std::vector<sf::Vector2f> pointPath;
  int s;

  bool moving=true;
  //II
  void findPath(const std::vector<std::string> &map,sf::Vector2f pointToWalk)
  {
    sf::Vector2f ObjCords={trunc(Body.getPosition().x/16),trunc(Body.getPosition().y/16)};
    std::vector<sf::Vector2f> pathLeft;
    pointToWalk={trunc(pointToWalk.x/16),trunc(pointToWalk.y/16)};
    int x=(pointToWalk.x-ObjCords.x),y=(pointToWalk.y-ObjCords.y),saveX=x;
    float j=0,h=(float)y/x;
    bool b=false,n=false;
    moving=false;


    if (x<0){b=true;x=-x;}
    if (y<0){n=true;y=-y;}
    //cout<<ObjCords.x<<' '<<ObjCords.y<<endl;

    int k=0;
    sf::Vector2f Point;
    do
    {
      j+=h;

      if (j>1){y+=1;j-=1;}

      Point={ObjCords.x+float((b)?-k:k),ObjCords.y+float((n)?-y:y)};

      if (map[Point.y][Point.x]==' '){pathLeft.push_back(Point);}
      else {break;}

      //cout<<"vector: "<<ObjCords.x+float((b)?-k:k)<<' '<<ObjCords.y+float((n)?-y:y)<<endl;
      k++;
    }while(k<x);

    pointPath=pathLeft;
  }
public:
  bool Remove;

  void move(const float &time)
  {
    Body.move(XYSpeed.x*time,XYSpeed.y*time);

    XYSpeed={0.0F,0.0F};
  }

  void Update(const sf::Vector2f PointCords,const std::vector<std::string> &map,const float time)
  {
    //cout<<4<<endl;
    if (moving){findPath(map,PointCords);s=0;}

    //cout<<trunc(Body.getPosition().x/16)<<trunc(Body.getPosition().y/16)<<endl;

    if (sf::Vector2f(trunc(Body.getPosition().x/16),trunc(Body.getPosition().y/16))==pointPath[s]){
      s++;

      //cout<<1<<endl;
      if (s==pointPath.size()){moving=true;return;}
    }

    //cout<<6<<endl;

    if (Body.getPosition().x<pointPath[s].x*16){XYSpeed.x=0.3F;}
    else if (Body.getPosition().x>pointPath[s].x*16){XYSpeed.x=-0.3F;}

    if (Body.getPosition().y<pointPath[s].y*16){XYSpeed.y=0.3F;}
    else if (Body.getPosition().y>pointPath[s].y*16){XYSpeed.y=-0.3F;}

    //cout<<trunc(Body.getPosition().x/16)<<' '<<trunc(Body.getPosition().y/16)<<endl<<endl;
    //cout<<pointPath[s].x<<' '<<pointPath[s].y<<endl;
    //cout<<5<<endl;
    move(time);
  }


  sf::Sprite &draw()
  {return Body;}

  sf::Vector2f getCords()
  {return Body.getPosition();}



  Enemy(const std::string FileDirectory,const imageArea Area,const sf::Vector2f Position):
  Soul(FileDirectory,Area,13,115),Remove(false)
  {
    Body.setPosition(Position);
    Body.setOrigin({Area.Width/2,Area.Heigth/1.5});
  }
};
