#pragma once

std::vector<std::string> SimbMapTest;

std::vector<std::string> BackgroundMapTest;
//////////////////////////////Classes///////////////////////////////
class Map
{
private:
  sf::Texture MapTexture;
  sf::Sprite MapSprite;

  std::vector<imageArea> SpritesArea={{5*16,9*16,16,16},{4*16,18*16,16,16},{4*16,17*16,16,16},{3*16,7*16,16,16},{2*16,6*16,16,16},{3*16,6*16,16,16},{4*16,6*16,16,16},
  {4*16,7*16,16,16},{4*16,8*16,16,16},{3*16,8*16,16,16},{2*16,8*16,16,16},{2*16,7*16,16,16},{2*16,9*16,16,16},{3*16,9*16,16,16},{2*16,10*16,16,16},{3*16,10*16,16,16},{0*16,29*16,16,16},{1*16,29*16,16,16},{2*16,29*16,16,16},{2*16,31*16,16,16},
  {0,30*16,16,16},{1*16,30*16,16,16},{2*16,30*16,16,16},{0,31*16,16,16},{1*16,31*16,16,16},{2*16,31*16,16,16},{5*16,11*16,16,16},{5*16,12*16,16,16},{6*16,10*16,16,16},
  {4*16,10*16,16,16}};


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


  std::vector<std::string> &getFrontMap()
  {return FrontMap;}

  std::vector<std::string> &getBackMap()
  {return BackMap;}



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



  Map(std::string FileDirectory,std::vector<std::string> &SimbMap1,std::vector<std::string> &SimbMap2):
  BackMap(SimbMap1.size()),FrontMap(SimbMap2.size())
  {
    MapTexture.loadFromFile(FileDirectory);
    MapSprite.setTexture(MapTexture);
    BackMap=SimbMap1;
    FrontMap=SimbMap2;
  }

};
