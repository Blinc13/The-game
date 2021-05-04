#pragma once
#include <fstream>

void loadMapFromTextFile(std::string FileName,std::vector<std::string> &Vector)
{
  std::ifstream MapFile;
  std::string Line;

  MapFile.open(FileName);

  while (std::getline(MapFile,Line))
  {
    Vector.push_back(Line);
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
