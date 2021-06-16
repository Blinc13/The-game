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
    virtual void setPosition(sf::Vector2i pos)=0;

    Widget(const Vector2i size,const Vector2i pos,RenderWindow *ptr):Size(size),Position(pos),MainWindow(ptr)
    {}

    virtual ~Widget(){}
};


class Butoon:public Widget
{
protected:
    mutable Sprite ButtonSprite;
    mutable Texture ButtonTexture;
    mutable imageArea TextureArea;

    Text Title;
    Font TextFont;

    void draw()
    {
        MainWindow->draw(ButtonSprite);
        MainWindow->draw(Title);
    }
public:
    void setPosition(sf::Vector2i pos)
    {
        ButtonSprite.setPosition(pos.x,pos.y);
        Title.setPosition(pos.x,pos.y);
    }

    bool show()
    {
        Vector2i mousePos=Mouse::getPosition(*MainWindow);

        if ((mousePos.x >= Position.x && mousePos.x <= Position.x+Size.x) && (mousePos.y >= Position.y && mousePos.y <= Position.y+Size.y))
        {
          ButtonSprite.setTextureRect(IntRect(TextureArea.x+TextureArea.Width,TextureArea.y,TextureArea.Width,TextureArea.Heigth));

          if (Mouse::isButtonPressed(Mouse::Left)){draw();return true;}
        }
        else {ButtonSprite.setTextureRect(IntRect(TextureArea.x,TextureArea.y,TextureArea.Width,TextureArea.Heigth));}


        draw();
        return false;
    }

    Butoon(const string TextureFileDirectory,const string FontFileDirectory,imageArea Area,const string str,RenderWindow *ptr,const Vector2i pos={0,0}):Widget({Area.Width,Area.Heigth},pos,ptr)
    {
      ButtonTexture.loadFromFile(TextureFileDirectory);
      TextFont.loadFromFile(FontFileDirectory);

      ButtonSprite.setTexture(ButtonTexture);
      ButtonSprite.setTextureRect(IntRect(Area.x,Area.y,Area.Width,Area.Heigth));
      ButtonSprite.setPosition(pos.x,pos.y);
      Title.setFont(TextFont);
      Title.setString(str);
      Title.setPosition(pos.x,pos.y);

      TextureArea=Area;
    }
};
