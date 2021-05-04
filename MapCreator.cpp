///////////////////////////////////By Blinc13////////////////21.04.2021
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "Funcs.hpp"
#include "View.hpp"
#include "Map.hpp"
using namespace std;


#define Key sf::Keyboard

class KeyBoard
{
private:
  bool EnterIsPressed=false;
  string BlockNumber;
  int BlockInputNum=0,BlockInputEnter=0;

public:
  #define KeyFind(Number,Num) if(Key::isKeyPressed(Key::Num)){BlockNumber+=Number;BlockInputNum=16;return;}
  void UpdateBlockNumber()
  {
    if (BlockInputNum<=0){
        KeyFind('0',Num0)
        KeyFind('1',Num1)
        KeyFind('2',Num2)
        KeyFind('3',Num3)
        KeyFind('4',Num4)
        KeyFind('5',Num5)
        KeyFind('6',Num6)
        KeyFind('7',Num7)
        KeyFind('8',Num8)
        KeyFind('9',Num9)

        if (Key::isKeyPressed(Key::Backspace)){BlockNumber="-16";BlockInputNum=16;}
    }

    BlockInputNum--;
    if (Key::isKeyPressed(Key::Return)&&BlockInputEnter<=0){EnterIsPressed=true;BlockInputEnter=30;}

    BlockInputEnter--;
  }

  int getMoveButton()
  {
    if (Key::isKeyPressed(Key::Up))     {return 0;}
    if (Key::isKeyPressed(Key::Down))   {return 1;}
    if (Key::isKeyPressed(Key::Left))   {return 2;}
    if (Key::isKeyPressed(Key::Right))  {return 3;}

    return 4;
  }

  ///////////////////////////////////////////////////////////

  void ResetEnter()
  {EnterIsPressed=false;}

  void ResetBlockNumber()
  {BlockNumber='0';}

  ////////////////////////////////////////////////////////////////

  bool CheckEnter()
  {return EnterIsPressed;}

  int GetBlockNumber()
  {
    //cout<<BlockNumber<<endl;
    return atoi(BlockNumber.c_str());
  }

  bool CheckSide()
  {return Key::isKeyPressed(Key::F);}

  ////////////////////////////////////////////////////////////////
  KeyBoard(): EnterIsPressed(false)
  {BlockNumber='0';}
};



class Editor
{
private:
  KeyBoard KeyboardInteraction  ;
  int SpeedMoving=0             ;
  sf::Vector2<int> Cords        ;

  sf::Image TextureImage        ;
  sf::Texture CenterTexture     ;
  sf::Sprite CenterSprite       ;

public:
  void Update(Map &map)
  {
    KeyboardInteraction.UpdateBlockNumber();

    if (SpeedMoving<=0){
      switch (KeyboardInteraction.getMoveButton())
      {
        case 0:
          move({0,-16});
          break;
        case 1:
          move({0,16});
          break;
        case 2:
          move({-16,0});
          break;
        case 3:
          move({16,0});
          break;
      }

      SpeedMoving=3;
    }

    if (KeyboardInteraction.CheckEnter()==true){
            if (KeyboardInteraction.CheckSide()){map.setBlockOnFrontMap(int(Cords.y)/16,int(Cords.x)/16,KeyboardInteraction.GetBlockNumber());}
            else {map.setBlockOnBackMap(int(Cords.y)/16,int(Cords.x)/16,KeyboardInteraction.GetBlockNumber());}


            KeyboardInteraction.ResetEnter();
            KeyboardInteraction.ResetBlockNumber();
    }

    SpeedMoving--;
  }

  void move(sf::Vector2<int> Speed)
  {
    Cords.x+=Speed.x;
    Cords.y+=Speed.y;

    CenterSprite.move(Speed.x,Speed.y);
  }

  void setCords(sf::Vector2<int> Cordinats)
  {
    Cords.x=Cordinats.x;
    Cords.y=Cordinats.y;
  }

  void ResetBlockOfMap(int x,int y)
  {}


  sf::Vector2<int> &getCords()
  {return Cords;}

  void draw(sf::RenderWindow &window)
  {window.draw(CenterSprite);}


  Editor(string FileDirectory)
  {
    TextureImage.loadFromFile(FileDirectory);
    TextureImage.createMaskFromColor(sf::Color::Black,80);

    CenterTexture.loadFromImage(TextureImage);
    CenterSprite.setTexture(CenterTexture);
    CenterSprite.setTextureRect(sf::IntRect(200,150,16,16));
  }
};




int main()
{
    std::vector<std::string> BackMap,FrontMap;
    std::string Test="Hello";

    loadMapFromTextFile("Maps/StandartMap/FrontMap.map", FrontMap);
    loadMapFromTextFile("Maps/StandartMap/BackMap.map", BackMap);

    sf::RenderWindow window(sf::VideoMode(600,300),"MapEditor");
    window.setFramerateLimit(60);
    Editor Edit("Sprites/Ui/Center.png");
    Cam View;
    Map map("Sprites/Objects/Overworld.png",BackMap,FrontMap);
    sf::Time time;

    cout<<char(1+48)<<endl;
    cout<<char(1)<<endl;

    Test[2]=char(2+48);


    while (true)
    {
      sf::Event WindowEvent;

      Edit.Update(map);

      if (window.pollEvent(WindowEvent)){
        if (WindowEvent.type==sf::Event::Closed){window.close();break;}
      }

      map.drawMap(window);
      View.setPosition(Edit.getCords());
      window.setView(View.getCamForDrav());
      Edit.draw(window);
      window.display();
      window.clear();
    }

    saveMapFile("Maps/StandartMap/FrontMap.map",map.getFrontMap());
    saveMapFile("Maps/StandartMap/BackMap.map",map.getBackMap());

    return 0;
}