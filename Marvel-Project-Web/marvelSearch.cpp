/***************************************************************************                   
 * marvelSearch.cpp  -  Program to display Marvel Character Information                                       
 *                                                                                             
 * Written by Jimmy Clark with code from Jim Skon                                                             
 *                                                                            
 * This program create an index of Marvel Characters                                               
 * It then allows you to click on any name and get information on the character.               
 *                                                            
 *     
 *
 ***************************************************************************/
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include "yearIndex.h"
#include "nameMap.h"
#include "nameIndex.h"
#include <string>

// Stuff for AJAX
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#define XML_USE_STL

using namespace std;
using namespace cgicc; // Needed for AJAX functions.

// File with the Marvel data.
const string path = "/home/students/clark1/marvelproject2/Marvel.csv";

int main() {
  // Object used for receiving AJAX call (and getting parameters)
  Cgicc cgi;    // Ajax object

  // Build the maps and indexes.
  nameMap test1(path);
  nameIndex index1(path);
  yearIndex index2(path);

  vector<int> matchList; // place to store the matches
  
  // Create AJAX objects to receive information from web page.
  form_iterator itts = cgi.getElement("type_select");
  form_iterator itname = cgi.getElement("name");//this is whatever the user inputs into the search box.

  // Retrieve the actual paramaters
  string type = **itts;
  string name = **itname;
  
  /* Convert name to lower case*/
  transform(name.begin(), name.end(), name.begin(), ::tolower);

  // Lookup the name in the appropriate name map
  if (type.compare("Name")==0) {
    matchList = index1.indexSearch(name);//use name index
  } else
    matchList = index2.indexSearch(name);//use year index

  
  /* send back the results */
  cout << "Content-Type: text/plain\n\n";

   if(matchList.size() == 0)
   cout << "No Matches"  << "," << " " << "," << " ";
   else{
   //send back all the individual parts of each character's info.
    for (int i = 0; i < matchList.size(); i++) {
    cout << i+1 << "." << "," <<  test1.getName(matchList[i]) << "," << test1.getLink(matchList[i]) << "," << test1.getAlliance(matchList[i]) << "," << test1.getIdentity(matchList[i]) << "," << test1.getEyes(matchList[i]) << "," << test1.getHair(matchList[i]) << "," << test1.getGender(matchList[i]) << "," << test1.getAlive(matchList[i]) << "," << test1.getAppearance(matchList[i]) << "," << test1.getFirst(matchList[i]) << "," << test1.getYear(matchList[i]);
    if (i<matchList.size()-1)
      cout << ","; // Only put out this comma if not last entry.
    }
   }
return 0;
}

