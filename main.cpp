#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
void listelement(const vector<string> &vec, string sep = " ", bool debug = false) {
  // Iterating over all elements of vector
  for (auto elem : vec) {
    if (debug) cout << elem << sep;
  }

  if (debug) cout << endl;
}

int main(int argc, char *argv[]) {
  // Check if the "--debug" flag was provided
  bool isDebug = false;
  for (int i = 0; i < argc; i++) {
    if (string(argv[i]) == "--debug") {
      isDebug = true;
      break;
    }
  }

  // Check if the "--file" flag was provided
  bool fileSpecified = false;
  for (int i = 0; i < argc; i++) {
    if (string(argv[i]) == "--file") {
      fileSpecified = true;
      if (i + 1 < argc) {
        // Read the code from the file specified by the next argument
        ifstream infile(argv[i + 1]);
        if (infile) {
          // Parse the code from the file
          string samplecode = string((istreambuf_iterator<char>(infile)),
                                     istreambuf_iterator<char>());
          infile.close();
          vector<string> codelist{};
          string buffer = "";
          for (int i = 0; i < samplecode.length(); i++) {
            if (samplecode[i] == ';') {
              codelist.push_back(buffer);
              buffer = "";
            } else {
              buffer = buffer + samplecode[i];
              if (isDebug) cout << buffer << endl;
            }
          }
          cout << codelist.size() << endl;
          listelement(codelist, ", ", isDebug);
        } else {
          // Failed to open the file
          cerr << "Error: Failed to open file '" << argv[i + 1] << "'" << endl;
          return 1;
        }
      } else {
        // The "--file" flag was provided, but no file was specified
        cerr << "Error: No file specified for '--file' flag" << endl;
        return 1;
      }
    }
  }

  if (!fileSpecified) {
    // The "--file" flag was not provided
    cerr << "Error: No file specified. Use the '--file' flag to specify a file to parse." << endl;
    return 1;
  }

  return 0;
}

