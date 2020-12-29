#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "characters.h"
using namespace std;

class nameIndex
{
  public:
    nameIndex(string filename);//constructor that creates the index.
    string lowercase(string str);//simple lowercase function.
    vector <int> indexSearch(string word);//searches the index for word and returns a vector of references.
    string getName(string str);//gets the name of a character.
    string formatInfo(string str);

  private:
    map<string, vector<int> > refs;//maps from character names to an int vector.
};
