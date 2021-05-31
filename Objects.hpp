#pragma once
#include <string>
#include <math.h>
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
  {
    BulletSprite.move(Speed);

    if (map[(int)BulletSprite.getPosition().y/16][(int)BulletSprite.getPosition().x/16]!=' '){Remove=true;}
  }

  inline void blockSide(int x,bool k)
  {/*Remove=!k;*/}

  void setPosition(sf::Vector2f &cords)
  {BulletSprite.setPosition(cords);}

  Sprite draw()
  {
      sf::Sprite sprite;
      sprite.setTexture(BulletTexture);
      return sprite;
}

  Vector2f getCords()
  {return BulletSprite.getPosition();}


  Bullet(string FileDirectory="Sprites/Ui/Center.png",imageArea TextureCords={100,100,4,4},Vector2f Cords={30,30},Vector2f speed={0,0}):Remove(false)
  {
    BulletTexture.loadFromFile("Sprites/Ui/Center.png");
    BulletSprite.setTexture(BulletTexture);

    BulletSprite.setTextureRect(IntRect(TextureCords.x,TextureCords.y,TextureCords.Width,TextureCords.Heigth));
    BulletSprite.setPosition(Cords);
    BulletSprite.setOrigin(TextureCords.Width/2,TextureCords.Heigth/2);

    cout<<TextureCords.x<<' '<<TextureCords.y<<endl;
    Speed=speed;
  }
};
