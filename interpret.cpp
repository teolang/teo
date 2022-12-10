#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<string> split(const string &str);

// Definition of the interpret function
void interpret(const vector<string> &codelist) {
  // Store variables in a map
  unordered_map<string, int> variables;

  // Iterate over the lines of code
  for (const auto &line : codelist) {
    // Split the line into tokens by space
    vector<string> tokens = split(line);

    // Handle the `let` command
    if (tokens[0] == "let") {
      // Get the name and value of the variable
      string name = tokens[1];
      int value = stoi(tokens[3]);

      // Set the value of the variable
      variables[name] = value;
    }

    // Handle the `print` command
    else if (tokens[0] == "print") {
      // Get the name of the variable to print
      string name = tokens[1];

      // Print the value of the variable
      cout << variables[name] << endl;
    }

    // Handle the `end` command
    else if (tokens[0] == "end") {
      // End the interpreter
      break;
    }

    // Handle unknown commands
    else {
      cerr << "Error: Unknown command '" << tokens[0] << "'" << endl;
    }
  }
}

// Helper function to split a string into tokens by space
vector<string> split(const string &str) {
  vector<string> tokens;
  string token;
  istringstream iss(str);
  while (getline(iss, token, ' ')) {
    tokens.push_back(token);
  }
  return tokens;
}
