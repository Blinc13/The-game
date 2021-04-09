class map
{
private:
  sf::Texture MapTexture;
  sf::Sprite MapSprite;

  std::vector<sf::String> SimbMap;
public:
  map(std::vector<sf::String> SimsbMap,std::string FileDirectory);
};


class Game
{
private:
  Hero hero;
  map GameMap;

public:
  Game(std::string FileDirectory);
};


#include "include/Game.cpp"
