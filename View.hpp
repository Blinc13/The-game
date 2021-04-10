struct imageArea
{
  int x,y;

  int width,heigth;
};





class Cam
{
private:
  sf::View Camera;
protected:

public:
///////////////////////set/////////////////////////
  template<class x>
  void setCamOnObj(const x &obj);

  void setZoom(float x)
  {Camera.zoom(x);}

  void setposition(float x,float y)
  {}
///////////////////////get/////////////////////////
  sf::View getCamForDrav()
  {
    return Camera;
  }

///////////////////////constructors////////////////

  Cam()
  {
    Camera.setSize(sf::Vector2f(300,200));
    Camera.zoom(5);
  }
};

template<class x>
void Cam::setCamOnObj(const x &obj)
{
  sf::Vector2f Centr=obj.getCords();
  Camera.setCenter(Centr);
}
