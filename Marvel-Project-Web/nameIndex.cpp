#include "nameIndex.h"
using namespace std;

nameIndex::nameIndex(string filename)
{
  string word, line;
  ifstream infile(filename); // open the file
  int position = 0;
  while (position != 16377) {
    getline(infile,line); // get the next line of code
    line = getName(line);//get the name of the character.
    line = lowercase(line);
    
    istringstream lineStream(line); // Create a string stream of the line
    while (lineStream >> word) { // get the next word
        refs[word].push_back(position); // push the word and the line position on the vector for this word.
    }

    position++; // get the position of the next line
}

infile.close();
}

string nameIndex::lowercase(string str)
{
  for (int i=0; i < str.length();i++)
  {
    str[i] = tolower(str[i]);
  }

  return str;
}

vector <int> nameIndex::indexSearch(string word)
{
  map<string, vector<int> >::iterator it;  // iterator for find                                                                
  vector<int> blank; // return for no matches                                                                                  
    /* find the word and get the vector of references */
    /* First use find, so as to NOT create a new entry */
    it = refs.find(word);
    if (it == refs.end()) {
         return(blank);
    } else {
        return (refs[word]);
    }
}

//this is a shortened version of the getInfo function from characters.h
string nameIndex::getName(string str)
{
  str = formatInfo(str);
  vector <string> infoList;

  istringstream lineStream(str);

  while (lineStream.good())
  {
    string word;
    getline(lineStream, word, ',');
    infoList.push_back(word);

  }

  if(infoList.size() >= 2)
  str = infoList[1];

  else
  str = "";

  return str;
}

//copied from characters.h
string nameIndex::formatInfo(string str)
{
  int i = 0, len = str.length();
    while (i < len) {
        char c = str[i];
        if (((c >= '0')&&(c <= '9')) || ((c >= 'A')&&(c <= 'Z')) || ((c >= 'a')&&(c <= 'z')) || c == '\'' || c == ' ' || c == '(' || c == ')') {
            ++i;
        } else {
            if (c == ','){
              ++i;
            }
            else{
            str.erase(i, 1);
            --len;
            }
          }
    }

    int temp = str.length();
    for(i=0; i<temp; i++)
    {
      if (str[i]==',')
      {
        str.insert(i+1," ");
        temp++;
        i++;
      }
    }



    return str;
}
