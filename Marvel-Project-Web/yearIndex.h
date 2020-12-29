#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "characters.h"
using namespace std;

class yearIndex
{
  public:
    yearIndex(string filename);//constructor that creates the index.
    string lowercase(string str);//simple lowercase function.
    vector <int> indexSearch(string word);//searches the index for a year and returns the references to the matches in a vector.
    void displayInfo(int reference);//displays the character info.
    string getYear(string str);//gets the year of the character.
    string formatInfo(string str);//makes the info neater.

  private:
    map<string, vector<int> > refs;//maps from a string containing a year to an int vector.
};
