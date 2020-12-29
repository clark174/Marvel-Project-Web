#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class characters
{
  public:
    characters(); //default constructor;
    characters(string aInfo); //assigns the line of the character to info.
    string formatInfo(string str); //removes special characters from the str and also adds spaces to make it look neater.
    vector <string> getInfo(string str); //assigns each section of info to the corresponding variable below.
    string info;
    string name;
    string link;
    string identity;
    string alliance;
    string eyes;
    string hair;
    string gender;
    string alive;
    string appearances;
    string firstAppearance;
    string firstYear;


  private:
};

#endif
