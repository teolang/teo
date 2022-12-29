#include <iostream>
#include <string>
#include <vector>
#include "codelistHandler.cpp"
#include "interpret.cpp" // include the header file for the interpret function
using namespace std;

int guihandler(string s) {
  // Read the code
  vector<string> codelist = parsehandler(s, true);
  if (codelist.empty()) {
    cerr << "Error: File is empty!." << endl;
    return 1;
  }
  // Interpret the code in the file
  interpret(codelist, true);

  return 0;
}
