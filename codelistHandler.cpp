#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> parsehandler(string samplecode, bool isDebug) {
  vector<string> codelist;
  string buffer = "";
  for (int i = 0; i < samplecode.length(); i++) {
    if (samplecode[i] == ';') {
      codelist.push_back(buffer);
      buffer = "";
    } else {
      buffer = buffer + samplecode[i];
      if (isDebug)
        cout << buffer << endl;
    }
  }
  // Remove escape character from new line
  for (auto &line : codelist) {
    line.erase(remove(line.begin(), line.end(), '\\'), line.end());
  }
  for (auto &line : codelist) {
    line.erase(remove(line.begin(), line.end(), '\n'), line.end());
  }
  return codelist;
}


