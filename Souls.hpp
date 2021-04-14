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
using namespace std;
enum Act
{
  move    = 0,
  attack  = 1,
};



class Soul
{
private:
  //Animation
  float AnStage;
protected:
  float Helth,Damage;
  bool UnlockSides[4]={1,1,1,1};


  imageArea TextureArea;
  sf::Texture BodyTexture;
  sf::Sprite Body;



  void AnimationFunc(const int Side,const float time)
  {
    if (Side==0){TextureArea.y=64;}
    else if (Side==1){TextureArea.y=0;}
    else if (Side==2){TextureArea.y=96;}
    else if (Side==3){TextureArea.y=32;}

    Body.setTextureRect(sf::IntRect(TextureArea.Width*int(AnStage),TextureArea.y,
                                    TextureArea.Width,TextureArea.Heigth));

    if (AnStage>=4.0F){AnStage=0;}


    AnStage+=time/20;
  }
public:
/////////////////////////Set//////////////////////////////

  void blockSide(int Position,bool x)
  {UnlockSides[Position]=x;}

  void resetBlockSides()
  {
    for (int k=0;k<4;k++)
        UnlockSides[k]=true;
  }

/////////////////////////Get//////////////////////////////

  bool getBlockSide(int Position)
  {return UnlockSides[Position];}

  Soul(std::string FileDirectory,const imageArea &Area)
  {
    BodyTexture.loadFromFile(FileDirectory);

    Body.setTexture(BodyTexture);
    Body.setTextureRect(sf::IntRect(Area.x,Area.y,
      Area.Width,Area.Heigth));


    TextureArea=Area;
    AnStage=0;
  }

};




class Hero: /*The endow with soul*/public Soul
{
protected:
  //Speed Data
  float SpeedX,SpeedY,MaxSpeed;

public:
////////////////////////////Set///////////////////////////////

  void move(const float x,const float y,const int Side,const float &Time)
  {
    Body.move(x,y);
    AnimationFunc(Side,Time);
  }

  void setPosition(const int x,const int y)
  {Body.setPosition(x,y);}

/////////////////////////////Get///////////////////////////////
  sf::Vector2f getCords() const
  {
    return Body.getPosition();
  }

  sf::Sprite Sprite() const
  {return Body;}


  Hero(std::string FileDirectory,imageArea Area,sf::Vector2f Cords,float MaxSpeedInput):
  Soul(FileDirectory,Area)
  {
    Body.setPosition(Cords.x,Cords.y);
    Body.setOrigin(Area.Width/2,Area.Heigth/2);
    SpeedX=0;
    SpeedY=0;
    MaxSpeed=MaxSpeedInput;
  }

};
