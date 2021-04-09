enum Act
{
  move    = 0,
  attack  = 1,

  // Возможно потом ещё добавлю
};

enum drivingSides
{
  Up      = 0,
  Down    = 1,
  left    = 2,
  right   = 3,
};


//////////////////Base entity class/////////////////
class Soul
{
private:
  //Animation
  float animationStage;
  drivingSides DriveSide;
protected:
  float helts,damage;

  void Animtion(imageArea Area)
  {

  };
public:
  virtual ~Soul()
  {

  }
};

///////////////////Base hero class///////////////////
class Hero: /*The endow with soul*/public Soul
{

};
