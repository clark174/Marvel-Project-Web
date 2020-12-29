#include "characters.h"
using namespace std;


characters::characters()
{
  info = "";
}


characters::characters(string aInfo)
{
  info = aInfo;
}

//the removeSpecials part of this code is from Prof. Skon's Shakespeare program
string characters::formatInfo(string str)
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
    //adds a space after every comma to make it look nicer.
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

vector<string> characters::getInfo(string str)
{

  string temp = str;

  temp.erase(remove(temp.begin(), temp.end(), '\\'),temp.end());

  vector<string> linkList;
  istringstream linkStream(temp);

  while(linkStream.good())
  {
   string word;
   getline(linkStream, word, ',');
   linkList.push_back(word);
  }

  link = "https://marvel.fandom.com/wiki" + linkList[2];

  str = formatInfo(str);
  vector <string> infoList;//vector to store the difference sections of the character info.

  istringstream lineStream(str);

  while (lineStream.good())
  {
    string word;
    getline(lineStream, word, ',');
    infoList.push_back(word);

  }

  //I left out the urlslug because I didn't think it was important.  Also, infoList[8] is blank for all the characters I think so I didn't include that as well.
  name = infoList[1];
  identity = infoList[3];
  alliance = infoList[4];
  eyes = infoList[5];
  hair = infoList[6];
  gender = infoList[7];
  alive = infoList[9];
  appearances = infoList[10];
  firstAppearance = infoList[11];
  firstYear = infoList[12];

 return infoList;
}

