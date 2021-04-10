////////////////////////By Blinc13////////////////////////////
////////////////////////Help//////////////////////////////////

/*drivingSides
{
  Up      = 0,
  Down    = 1,
  Left    = 2,
  Right   = 3,
}*/

/////////////////////////CODE/////////////////////////////////
//////////////////////////////////////////////////////////////

int getMoveButtons()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){return 0;}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){return 1;}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){return 2;}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){return 3;}
  return 4;
}




///////////////////////////Main control////////////////////////////////////////
void controlHero(Hero &hero)
{
  switch (getMoveButtons())
  {
    case 0:
      hero.move(0,-0.1F,0);
      break;
    case 1:
      hero.move(0,0.1F,1);
      break;
    case 2:
      hero.move(-0.1F,0,2);
      break;
    case 3:
      hero.move(0.1F,0,3);
      break;
  }
}
