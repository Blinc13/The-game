#pragma once
#include <string>
using namespace std;
using namespace sf;

class Bullet
{
private:
  Vector2f Speed;

  Texture BulletTexture;
  Sprite BulletSprite;
public:
  bool Remove;
  float Damage;


  void Update(const sf::Vector2f cords,const std::vector<std::string> &map,const float time)
  {BulletSprite.move(Speed);}

  void blockSide(int x,bool k)
  {Remove=!k;}

  void setPosition(sf::Vector2f &cords)
  {BulletSprite.setPosition(cords);}

  Sprite &draw()
  {return BulletSprite;}

  Vector2f getCords()
  {return BulletSprite.getPosition();}


  Bullet(string FileDirectory="Sprites/Ui/Center.png",imageArea TextureCords={300,300,4,4},Vector2f Cords={30,30},Vector2f speed={0,0}):
  Remove(false)
  {
    BulletTexture.loadFromFile(FileDirectory);
    BulletSprite.setTexture(BulletTexture);

    BulletSprite.setTextureRect(IntRect(TextureCords.x,TextureCords.y,TextureCords.Width,TextureCords.Heigth));
    BulletSprite.setPosition(Cords);

    Speed=speed;
  }
};
