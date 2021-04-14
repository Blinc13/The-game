//////////////////////////////By Blinc13////////////////////////////
//////////////////////////////Test//////////////////////////////////
#pragma once
using namespace std;

std::vector<std::string> SimbMapTest={
  "500000000000000000004",
  "1   1               1",
  "1       1           1",
  "1                   1",
  "1                   1",
  "200000000000000000003"
};

std::vector<std::string> BackgroundMap={
  "                     ",
  "                     ",
  "                     ",
  "                     ",
  "                     ",
  "                     "
};

//////////////////////////////Classes///////////////////////////////
class Map
{
private:
  sf::Texture MapTexture;
  sf::Sprite MapSprite;

  std::vector<std::string> BackMap,FrontMap;

  void drawCl(imageArea area,sf::RenderWindow &window,int k,int j,float Rotation=0,sf::Vector2f move={0,0})
  {
    MapSprite.setTextureRect(sf::IntRect(area.x,area.y,area.Width,area.Heigth));
    MapSprite.setPosition(j*15,k*15);
    MapSprite.move(move.x,move.y);
    MapSprite.setRotation(Rotation);
    window.draw(MapSprite);
    MapSprite.setRotation(0);
  }
public:
  std::vector<std::string> &getSimbMap()
  {
    return FrontMap;
  }

  void drawMap(sf::RenderWindow &window)
  {
    for (int k=0;k<FrontMap.size();k++){
      for (int j=0;j<FrontMap[1].size();j++){
        //cout<<4<<endl;
        if (BackgroundMap[k][j]==' '){drawCl({32,256,15,15},window,k,j);}
        if (SimbMapTest[k][j]=='0'){
          drawCl({64,272,15,15},window,k,j);
        }

        else if (SimbMapTest[k][j]=='1'){
          drawCl({64,272,15,15},window,k,j,90.0F,{15,0});
        }
        //cout<<5<<endl;
      }
      //cout<<6<<endl;
    }
  }



  Map(std::string FileDirectory,std::vector<std::string> SimbMap1,std::vector<std::string> SimbMap2):
  BackMap(SimbMap1.size()),FrontMap(SimbMap2.size())
  {
    MapTexture.loadFromFile(FileDirectory);
    MapSprite.setTexture(MapTexture);
    BackMap=SimbMap1;
    FrontMap=SimbMap2;
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
