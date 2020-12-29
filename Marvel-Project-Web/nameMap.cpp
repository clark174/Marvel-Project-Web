#include "nameMap.h"
using namespace std;

nameMap::nameMap(string filename)
{
    ifstream infile(filename);//open the file
    string line;
    int position = 0;
    if (infile.good()) {
        while (position != 16377) {
            getline(infile, line);//get the next line of the file.
            characters characterData(line);//fill in the character variables for characterData.
	characterData.getInfo(line);
            if (infile.fail()) break;
            characterList.push_back(characterData);//push the character object onto the end of the list.
	position++;    
    }
        infile.close();
    }
    else
    {
      infile.close();
    }
}

void nameMap::displayName(int reference)
{
    cout << characterList[reference].name;
}

string nameMap::getName(int reference)
{
  return characterList[reference].name;
}

string nameMap::getIdentity(int reference)
{
   return characterList[reference].identity;
}

string nameMap::getAlliance(int reference)
{
   return characterList[reference].alliance;
}

string nameMap::getLink(int reference)
{
  return characterList[reference].link;
}

string nameMap::getEyes(int reference)
{
  return characterList[reference].eyes;
}

string nameMap::getHair(int reference)
{
  return characterList[reference].hair;
}

string nameMap::getGender(int reference)
{
  return characterList[reference].gender;
}

string nameMap::getAlive(int reference)
{
  return characterList[reference].alive;
}

string nameMap::getAppearance(int reference)
{
  return characterList[reference].appearances;
}

string nameMap::getFirst(int reference)
{
  return characterList[reference].firstAppearance;
}

string nameMap::getYear(int reference)
{
  return characterList[reference].firstYear;
}

//displays all of the character information in a neat order.
void nameMap::displayInfo(int reference)
{
  cout << "Name:" << characterList[reference].name << "\nIdentity:" << characterList[reference].identity << "\nAlliance:" << characterList[reference].alliance << "\nEye Color:" << characterList[reference].eyes << "\nHair Color:" << characterList[reference].hair << "\nGender:" << characterList[reference].gender << "\nAlive or Dead:" << characterList[reference].alive << "\nNumber of Appearances in the Marvel Universe:" << characterList[reference].appearances << "\nDate of First Appearance:" << characterList[reference].firstAppearance << "\nYear of First Appearance:" << characterList[reference].firstYear;
}
