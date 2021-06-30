#pragma once
#include <iomanip>
#include "Widgets.hpp"
#include <string>


class Ui
{
private:
  sf::Texture UiElementsTexture;
  sf::Font TextFont;
  sf::Text Text;

  std::vector<sf::Sprite> UiElements;
  std::ostringstream HealthStream;


  inline void drawLineOfElements(sf::Sprite &Sprite,sf::RenderWindow *Window,float SizeX,int Count)
  {
    for (int k=0;k<Count;k++)
    {
      Window->draw(Sprite);

      Sprite.move(SizeX,0.0F);
    }
  }
public:
  void drawUi(sf::RenderWindow *Window,Cam *View,int health,int bullets,int res)
  {
    std::string StrHealth = std::to_string(health);
    sf::Vector2f UiCenter = View->getPosition();

    HealthStream<<"- "<<std::setw(3)<<StrHealth;
    UiElements[0].setPosition(UiCenter.x-250,UiCenter.y-120);
    Text.setPosition(UiCenter.x-235,UiCenter.y-125);
    Text.setString(HealthStream.str());
    Window->draw(Text);

    HealthStream.str("");

    UiElements[1].setPosition(UiCenter.x-250,UiCenter.y-80);
    drawLineOfElements(UiElements[1],Window,2*3,bullets);

    UiElements[2].setPosition(UiCenter.x-250,UiCenter.y-100);
    HealthStream<<"- "<<std::setw(3)<<res;
    Text.setPosition(UiCenter.x-235,UiCenter.y-104);
    Text.setString(HealthStream.str());
    Window->draw(UiElements[2]);
    Window->draw(Text);

    HealthStream.str("");

    Window->draw(UiElements[0]);
    //std::cout<<"complite"<<std::endl;
  }


  Ui(std::string FileDirectory,std::string FontFileDirectory):UiElements(4)
  {
    UiElementsTexture.loadFromFile(FileDirectory);
    UiElements[0].setTexture(UiElementsTexture);
    UiElements[0].setTextureRect(sf::IntRect(64,2,14,13));

    UiElements[1].setTexture(UiElementsTexture);
    UiElements[1].setTextureRect(sf::IntRect(9,298,2,3));
    UiElements[1].setScale(3,3);

    UiElements[2].setTexture(UiElementsTexture);
    UiElements[2].setTextureRect(sf::IntRect(260,20,10,7));
    UiElements[2].setScale(1.8F,1.8F);

    TextFont.loadFromFile(FontFileDirectory);
    Text.setFont(TextFont);
    Text.setScale(0.5F,0.5F);
  }
};


class Menu
{
protected:
    std::vector<Widget*> Widgets;
public:
    int draw()
    {
        int Active=-1;

        for (int k=0;k<Widgets.size();k++)
            if (Widgets[k]->show()){Active=k;}

        return Active;
    }

    void addWidget(Widget *widget)
    {Widgets.push_back(widget);}

    Widget* operator[](const int k) const
    {return Widgets[k];}

    Menu(){}

    ~Menu(){
        for (int k=0;k<Widgets.size();k++)
            delete Widgets[k];
    }
};
