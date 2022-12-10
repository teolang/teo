#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Definition of the listelement function
void listelement(const vector<string> &vec, string sep, bool debug) {
  // Iterating over all elements of vector
  for (auto elem : vec) {
    if (debug) cout << elem << sep;
  }

  if (debug) cout << endl;
}

