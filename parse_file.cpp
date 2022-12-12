#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "codelistHandler.cpp"

using namespace std;

// Definition of the parse_file function
vector<string> parse_file(int argc, char *argv[], bool isDebug) {
  vector<string> codelist{};
  bool fileSpecified = false;
  for (int i = 0; i < argc; i++) {
    if (string(argv[i]) == "--stdin") {
      // Read the code from stdin
      string samplecode =
          string((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());
      codelist = parsehandler(samplecode, isDebug);
    } else if (string(argv[i]) == "--file") {
      fileSpecified = true;
      if (i + 1 < argc) {
        // Read the code from the file specified by the next argument
        ifstream infile(argv[i + 1]);
        if (infile) {
          // Parse the code from the file
          string samplecode = string((istreambuf_iterator<char>(infile)),
                                     istreambuf_iterator<char>());
          infile.close();
          codelist = parsehandler(samplecode, isDebug);
        } else {
          // Failed to open the file
          cerr << "Error: Failed to open file '" << argv[i + 1] << "'" << endl;
          return codelist;
        }
      } else {
        // The "--file" flag was provided, but no file was specified
        cerr << "Error: No file specified for '--file' flag" << endl;
        return codelist;
      }
    }
  }

  if (!fileSpecified) {
    // The "--file" flag was not provided
    cerr << "Error: No file specified. Use the '--file' flag to specify a file "
            "to parse."
         << endl;
  }

  return codelist;
}
