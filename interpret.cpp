#include "parse_file.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void interpret(const vector<string> &code_lines, const bool is_debug) {
  // Create a map to store variables and their values
  map<string, string> variables{};

  // Iterate over each line of code
  for (const string &line : code_lines) {
    // Split the line into tokens
    vector<string> tokens{};
    string token{};
    stringstream ss{line};
    while (ss >> token) {
      tokens.push_back(token);
    }

    // Check the first token to determine the command
    if (tokens[0] == "let") {
      // Handle the "let" command
      if (tokens.size() != 3) {
        // Invalid number of tokens for the "let" command
        cerr << "Error: Invalid number of tokens for 'let' command" << endl;
        continue;
      }

      // Store the variable and its value in the map
      variables[tokens[1]] = tokens[2];
    } else if (tokens[0] == "print") {
      // Handle the "print" command
      if (tokens.size() != 2) {
        // Invalid number of tokens for the "print" command
        cerr << "Error: Invalid number of tokens for 'print' command" << endl;
        continue;
      }

      // Look up the variable in the map and print its value
      if (variables.count(tokens[1]) > 0) {
        cout << variables[tokens[1]] << endl;
      } else {
        // Variable not found
        cerr << "Error: Variable '" << tokens[1] << "' not found" << endl;
      }
    } else if (tokens[0] == "end") {
      // Handle the "end" command
      if (tokens.size() != 1) {
        // Invalid number of tokens for the "end" command
        cerr << "Error: Invalid number of tokens for 'end' command" << endl;
        continue;
      }

      // Stop interpreting the code
      break;
    } else {
      // Unknown command
      cerr << "Error: Unknown command '" << tokens[0] << "'" << endl;
    }
  }
}
