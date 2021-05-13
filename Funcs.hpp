#pragma once
#include <fstream>

void loadMapFromTextFile(const std::string FileName,std::vector<std::string> &Vector,const std::string Simb)
{
  std::ifstream MapFile;
  std::string Line;

  MapFile.open(FileName);

  while (std::getline(MapFile,Line)&&MapFile.good())
  {
    Vector.push_back(Line);
  }

  if (Vector.empty())
  {
    Vector.resize(0);

    for (int k=0;k<52;k++)
    {
      for (int j=0;j<73;j++)
      {
        Line+=Simb;
      }

      Vector.push_back(Line);
      Line="";
    }
  }
}


void saveMapFile(std::string FileDirectory,std::vector<std::string> &Vector)
{
  std::fstream File(FileDirectory);

  for (int k=0;k<Vector.size();k++)
  {
    File<<Vector[k]<<'\n';
    std::cout<<Vector[k]<<std::endl;
  }

}
