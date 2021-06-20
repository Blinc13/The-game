#include "Widgets.hpp"
#include "Ui.hpp"
#include <iostream>
#include "Funcs.hpp"
using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(700,500),"Test");
  Menu *menu=loadMenuFromFile("/home/blinc/The_game_Unstable/Conf/Menu.conf",&window);

  while (true)
  {
    menu->draw();

    window.display();
    window.clear(sf::Color::Yellow);
  }
  return 0;
}
