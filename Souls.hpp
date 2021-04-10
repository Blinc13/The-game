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



enum Act
{
  move    = 0,
  attack  = 1,
};



struct AnimationStruct
{
  float AnimationStage;
  drivingSides DriveSide;
  Act Action;
  imageArea Area;
};



class Soul
{
private:
  //Animation
  AnimationStruct Animation;
protected:
  float Helth,Damage;


  imageArea TextureArea;
  sf::Texture BodyTexture;
  sf::Sprite Body;



  void AnimationFunc()
  {

  }
public:





  Soul(std::string FileDirectory,const imageArea &Area)
  {
    BodyTexture.loadFromFile(FileDirectory);

    Body.setTexture(BodyTexture);
    Body.setTextureRect(sf::IntRect(Area.x,Area.y,
      Area.width,Area.heigth));


    TextureArea=Area;
  }

};




class Hero: /*The endow with soul*/public Soul
{
protected:
  speedXY Speed;

public:
  void move(const float x,const float y,const int Side)
  {
    Body.move(x,y);
  }

  void setPosition(const int x,const int y)
  {
    Body.setPosition(x,y);
  }

  sf::Vector2f getCords() const
  {
    return Body.getPosition();
  }

  sf::Sprite Sprite() const
  {return Body;}


  Hero(std::string FileDirectory,imageArea Area,Cord Cords,float MaxSpeed):
  Soul(FileDirectory,Area)
  {
    Body.setPosition(Cords.x,Cords.y);
    Speed.x=0;
    Speed.y=0;
    Speed.MaxSpeed=MaxSpeed;
    Body.setScale(2,2);
  }

};
