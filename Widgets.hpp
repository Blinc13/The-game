#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "View.hpp"

using namespace sf;
using namespace std;
//Чёто типо Qt, но не Qt


class Widget
{
protected:
    Vector2i Position;
    Vector2i Size;

    RenderWindow *MainWindow;
public:
    virtual bool show()=0;

    Widget(const Vector2i size,const Vector2i pos,RenderWindow *ptr):Size(size),Position(pos),MainWindow(ptr)
    {}
};


class Butoon:public Widget
{
protected:
    mutable Sprite ButtonSprite;
    mutable Texture ButtonTexture;
    mutable imageArea TextureArea;

    Text Title;
    Font TextFont;
public:
    bool show()
    {
        Vector2i mousePos=Mouse::getPosition(*MainWindow);

        if ((mousePos.x >= Position.x && mousePos.x <= Position.x+Size.x) && (mousePos.y >= Position.y && mousePos.y <= Position.y+Size.y))
        {
          if (Mouse::isButtonPressed(Mouse::Left)){return true;}

          ButtonSprite.setTextureRect(IntRect(TextureArea.x+TextureArea.Width,TextureArea.y,TextureArea.Width,TextureArea.Heigth));
        }
        else {ButtonSprite.setTextureRect(IntRect(TextureArea.x,TextureArea.y,TextureArea.Width,TextureArea.Heigth));}


        MainWindow->draw(ButtonSprite);
        return false;
    }

    Butoon(const string TextureFileDirectory,const string FontFileDirectory,imageArea Area,const string str,RenderWindow *ptr,const Vector2i pos={0,0}):Widget({Area.Width,Area.Heigth},pos,ptr)
    {
      ButtonTexture.loadFromFile(TextureFileDirectory);
      ButtonSprite.setTexture(ButtonTexture);
      ButtonSprite.setTextureRect(IntRect(Area.x,Area.y,Area.Width,Area.Heigth));

      TextureArea=Area;
      Title.setString(str);
    }
};
