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
      buffer.erase(remove(buffer.begin(), buffer.end(), '\\'), buffer.end());
      buffer.erase(remove(buffer.begin(), buffer.end(), '\n'), buffer.end());
      if (isDebug) {
        cout << buffer << endl;
      }
    }
  }
  return codelist;
}


