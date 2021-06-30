#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
//////////////////////////////Classes///////////////////////////////
class Map
{
private:
  sf::Texture MapTexture;
  sf::Sprite MapSprite;

  std::vector<imageArea> SpritesArea;


  std::vector<std::string> BackMap,FrontMap;



  void drawCl(const imageArea area,sf::RenderWindow &Window,int k,int j,float Rotation=0,sf::Vector2f move={0,0})
  {
    MapSprite.setTextureRect(sf::IntRect(area.x,area.y,area.Width,area.Heigth));
    MapSprite.setPosition(j*16,k*16);
    MapSprite.move(move.x,move.y);
    MapSprite.setRotation(Rotation);
    Window.draw(MapSprite);
    MapSprite.setRotation(0);
  }

public:
  void setBlockOnFrontMap(int x,int y,int BlockNumber)
  {FrontMap[x][y]=char(BlockNumber+48);}

  void setBlockOnBackMap(int x,int y,int BlockNumber)
  {BackMap[x][y]=char(BlockNumber+48);}


  std::vector<std::string> *getFrontMap()
  {return &FrontMap;}

  std::vector<std::string> *getBackMap()
  {return &BackMap;}

  std::vector<imageArea> &getVecOfTextures()
  {return SpritesArea;}



  void drawMap(sf::RenderWindow &Window)
  {
    int MapElem;

    for (int k=0;k<FrontMap.size();k++)
      for (int j=0;j<FrontMap[1].size();j++){

        switch (BackMap[k][j]-48){
          case -16:
            break;
          default:
            drawCl(SpritesArea[int(BackMap[k][j])-48],Window,k,j);
        }
      //}

    /*for (int k=0;k<FrontMap.size();k++)
      for (int j=0;j<FrontMap[k].size();j++){*/
        MapElem=(static_cast<int>(FrontMap[k][j]))-48;
        //std::cout<<MapElem<<std::endl;

        switch (MapElem)
        {
          case -16:
            break;
          default:
            drawCl(SpritesArea[MapElem],Window,k,j);
        }
        //std::cout<<5<<std::endl;
      //std::cout<<6<<std::endl;
      }
  }



  Map(std::string FileDirectory,std::vector<std::string> &Back,std::vector<std::string> &Front):
  BackMap(Back.size()),FrontMap(Front.size())
  {
    MapTexture.loadFromFile(FileDirectory);
    MapSprite.setTexture(MapTexture);

    BackMap     =Back  ;
    FrontMap   =Front;
  }
};
