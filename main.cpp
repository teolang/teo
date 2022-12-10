#include <iostream>
#include <string>
#include <vector>
using namespace std;
void listelement(const vector<string> &vec, string sep = " ") {
  // Iterating over all elements of vector
  for (auto elem : vec) {
    cout << elem << sep;
  }

  cout << endl;
}

int main() {
  // Sample debug code
  string samplecode = "VAR X = 0; PRINT X;";
  vector<string> codelist{};
  string buffer = "";
  for (int i = 0; i < samplecode.length(); i++) {
    if (samplecode[i] == ';') {
      codelist.push_back(buffer);
      buffer = "";
    } else {
      buffer = buffer + samplecode[i];
      cout << buffer << endl;
    }
  }
  cout << codelist.size() << endl;
  listelement(codelist, ", ");
  return 0;
}
