#include <iostream>
#include <string>
#include <vector>
#include "parse_file.h" // include the header file for the parse_file function
#include "interpret.h" // include the header file for the interpret function
using namespace std;

int main(int argc, char *argv[]) {
  // Check if the "--debug" flag was provided
  bool isDebug = false;
  for (int i = 0; i < argc; i++) {
    if (string(argv[i]) == "--debug") {
      isDebug = true;
      break;
    }
  }
  if (isDebug){
    const char *buildString = "Compiled at " __DATE__ ", " __TIME__ ".";
    cout << buildString << endl;
    printf("Git ref: %s\n", VERSION);
  }
  // Check if the "--file" flag was provided
  vector<string> codelist = parse_file(argc, argv, isDebug);
  if (codelist.empty()) {
    // The "--file" flag was not provided or an error occurred while parsing the file
    cerr << "Error: File is empty!." << endl;
    return 1;
  }
  // Interpret the code in the file
  interpret(codelist, isDebug);

  return 0;
}
