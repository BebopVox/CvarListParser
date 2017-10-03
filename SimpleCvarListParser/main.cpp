#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void main()
{
  ifstream inputfile("cvars.txt");
  ofstream outFile("cvars_result.txt");
        
  string tempstr;

  while (getline(inputfile, tempstr))
  {
    if (tempstr.find("\"launcher\"") == string::npos
        && tempstr.find("\"sv\"") == string::npos
        //&& tempstr.find("\"rep\"") == string::npos
        && tempstr.substr(0, 3).compare("sv_") != 0
        && tempstr.find(": cmd") == string::npos)
    {
      outFile << tempstr << endl;
    }
  }
  outFile.close();
  inputfile.close();
}
