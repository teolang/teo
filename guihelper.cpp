#include <iostream>
#include <string>
#include <vector>
#include "codelistHandler.h"
#include "interpret.h" // include the header file for the interpret function
#include "guihelper.h"
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
