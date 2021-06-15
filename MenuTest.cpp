#include "Widgets.hpp"


int main()
{
  sf::RenderWindow window(sf::VideoMode(700,500),"Test");
  Butoon button("/home/blinc/The_game_Unstable/Sprites/Ui/objects.png","/home/blinc/The_game_Unstable/Fonts/Ubuntu_Mono/UbuntuMono-Bold.ttf",{0,0,100,100},"Hello",&window);

  while (true)
  {
    button.show();

    window.display();
    window.clear();
  }
  return 0;
}
