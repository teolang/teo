#include <iostream>
#include <string>
#include <vector>
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

  // Sample debug code
  string samplecode = "VAR X = 0;PRINT X;";
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
  return 0;
}

