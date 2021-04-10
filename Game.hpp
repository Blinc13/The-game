//////////////////////////////By Blinc13////////////////////////////
//////////////////////////////Test//////////////////////////////////
std::string SimbMapTest[]={
  "0000000000",
  "          "
};



//////////////////////////////Classes///////////////////////////////
class Map
{
private:
  sf::Texture MapTexture;
  sf::Sprite MapSprite;
public:
  Map(std::string FileDirectory)
  {
    MapTexture.loadFromFile(FileDirectory);
    MapSprite.setTexture(MapTexture);
  }

  void drawMap(sf::RenderWindow &window)
  {
    for (int k=0;k<2;k++){
      for (int j=0;j<10;j++){
        if (SimbMapTest[k][j]=='0'){
          MapSprite.setTextureRect(sf::IntRect(0,0,200,200));
          MapSprite.setPosition(j*200,k*200);
          window.draw(MapSprite);
        }
        else if (SimbMapTest[k][j]==' '){
          MapSprite.setTextureRect(sf::IntRect(194,194,100,100));
          MapSprite.setPosition(j*100,k*200);
          window.draw(MapSprite);
        }
      }
    }
  }
};


class Game
{
private:
  Hero hero;
  Map GameMap;

public:
  void update();
  Game(std::string FileDirectory);
};
