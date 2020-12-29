#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "characters.h"

using namespace std;

class nameMap
{
  public:
    nameMap(string filename);//constructor that fills characterList with the characters.
    void displayName(int reference);//displays the name of the character.
    void displayInfo(int reference);//displays the info of the character.
    string getName(int reference);
    string getIdentity(int reference);
    string getAlliance(int reference); 
    string getLink(int reference);
    string getEyes(int reference);
    string getHair(int reference);
    string getGender(int reference);
    string getAlive(int reference);
    string getAppearance(int reference);
    string getFirst(int reference);
    string getYear(int reference);
    private:
    vector <characters> characterList;//vector to store the characters.
};
