#pragma once
#include <iomanip>

class Ui
{
private:
  sf::Texture UiElementsTexture;
  sf::Font TextFont;
  sf::Text HealthText;

  std::vector<sf::Sprite> UiElements;
  std::ostringstream HealthStream;


  inline void drawLineOfElements(sf::Sprite &Sprite,sf::RenderWindow &Window,float SizeX,int Count)
  {
    for (int k=0;k<Count;k++)
    {
      Window.draw(Sprite);

      Sprite.move(SizeX,0.0F);
    }
  }
public:
  void drawUi(sf::RenderWindow &Window,Cam &View,int health,int bullets)
  {
    std::string StrHealth = std::to_string(health);
    sf::Vector2f UiCenter = View.getPosition();

    HealthStream<<"- "<<std::setw(3)<<StrHealth;
    UiElements[0].setPosition(UiCenter.x-250,UiCenter.y-120);
    HealthText.setPosition(UiCenter.x-235,UiCenter.y-125);
    HealthText.setString(HealthStream.str());
    Window.draw(HealthText);

    UiElements[1].setPosition(UiCenter.x-250,UiCenter.y-104);
    drawLineOfElements(UiElements[1],Window,2*3,bullets);
    //cout<<UiCenter.x-50<<' '<<UiCenter.y-16<<std::endl;

    Window.draw(UiElements[0]);
    //std::cout<<"complite"<<std::endl;

    HealthStream.str("");
  }


  Ui(std::string FileDirectory,std::string FontFileDirectory):UiElements(4)
  {
    UiElementsTexture.loadFromFile(FileDirectory);
    UiElements[0].setTexture(UiElementsTexture);
    UiElements[0].setTextureRect(sf::IntRect(64,2,14,13));

    UiElements[1].setTexture(UiElementsTexture);
    UiElements[1].setTextureRect(sf::IntRect(9,298,2,3));
    UiElements[1].setScale(3,3);

    TextFont.loadFromFile(FontFileDirectory);
    HealthText.setFont(TextFont);
    HealthText.setScale(0.5F,0.5F);
  }
};
