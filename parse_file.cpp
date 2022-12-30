#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "codelistHandler.h"

using namespace std;

// Definition of the parse_file function
vector<string> parse_file(int argc, char *argv[], bool isDebug) {
  vector<string> codelist{};
  bool fileSpecified = false;
  for (int i = 0; i < argc; i++) {
    if (string(argv[i]) == "--stdin") {
      fileSpecified = true;
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
    } else if (string(argv[i]).rfind("--test=", 0) == 0) {
      fileSpecified = true;
      int testnum = stoi(string(argv[i]).substr(7));
      string testname;
      switch (testnum)
      {
      case 1:
        testname = "Assertion";
        codelist = parsehandler("let x 5;let x x+2;let y 5;assert x > y "
                              "5+1;print x;print x;print y*2;end;",
                              false);
        break;
      case 2:
        testname = "For loop";
        codelist =
          parsehandler("let x 0;let x x+1;assert x < 10 2;print x;", false);
        break;
      case 3:
        testname = "Circle";
        codelist =
          parsehandler("let pi 22/7;print pi*pow(5,2);", false);
        break;
      default:
        break;
      }
      if (isDebug) {
        printf("\033[1;92mTesting   \033[1;93m \033[0m%s: %s\n", to_string(testnum).c_str(), string(testname).c_str());
      }
      return codelist;
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
