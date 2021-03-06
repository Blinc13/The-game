#pragma once
#include <fstream>
#include "View.hpp"
#include "Widgets.hpp"
#include "Ui.hpp"

void loadMapFromTextFile(const std::string FileName,std::vector<std::string> &Vector,const std::string Simb)
{
  std::ifstream MapFile;
  std::string Line;

  MapFile.open(FileName);

  while (std::getline(MapFile,Line)&&MapFile.good())
  {
    Vector.push_back(Line);
  }

  if (Vector.empty())
  {
    Vector.resize(0);

    for (int k=0;k<52;k++)
    {
      for (int j=0;j<73;j++)
      {
        Line+=Simb;
      }

      Vector.push_back(Line);
      Line="";
    }
  }
}


void saveMapFile(const std::string FileDirectory,std::vector<std::string> &Vector)
{
  std::fstream File(FileDirectory);

  for (int k=0;k<Vector.size();k++)
  {
    File<<Vector[k]<<'\n';
   // std::cout<<Vector[k]<<std::endl;
  }

}

void loadVecOfSpritesTexture(const std::string FileDirectory,std::vector<imageArea> &Vector)
{
  std::ifstream File(FileDirectory);

  Vector.resize(35);

  for (int k=0;File.good();k++)
  {
    File>>Vector[k].x     ;
    File>>Vector[k].y     ;
    File>>Vector[k].Width ;
    File>>Vector[k].Heigth;
  }
}

Menu* loadMenuFromFile(const std::string FileDirectory,sf::RenderWindow *window)
{
  Menu *MenuPtr=new Menu("Sprites/Ui/MenuGround.png",window);
  fstream File(FileDirectory);
  int NumOfWidgets;
  std::string NameOfWidget,TextureFile,FontFile,Text;
  sf::Vector2i Position;
  imageArea Area;
  sf::Vector2f Size;

  File>>NumOfWidgets;

  for (int k=0;k<NumOfWidgets;k++)
  {
    File>>NameOfWidget>>TextureFile>>FontFile>>Area.x>>Area.y>>Area.Width>>Area.Heigth>>Text>>Position.x>>Position.y>>Size.x>>Size.y;

    if (NameOfWidget=="Button"){
      MenuPtr->addWidget(new Butoon(TextureFile,FontFile,Area,Size,Text,window,Position));
    }
  }


  return MenuPtr;
}
