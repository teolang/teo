// let.cpp

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>

// Definition of the tok_let function
void tok_let(const std::string &line, std::map<std::string, int> &vars,
             const bool is_debug) {
  // Split the line into tokens
  std::istringstream iss(line);
  std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                  std::istream_iterator<std::string>{}};

  if (tokens.size() != 3) {
    if (is_debug) {
      std::cerr << "Error: Invalid number of arguments for 'let' command"
                << std::endl;
    }
    return;
  }

  // Check if the variable name is valid
  if (tokens[1].find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_") != std::string::npos) {
    if (is_debug) {
      std::cerr << "Error: Invalid variable name '" << tokens[1] << "'"
                << std::endl;
    }
    return;
  }

  // Check if the value is an integer
  if (tokens[2].find_first_not_of("0123456789") != std::string::npos) {
    if (is_debug) {
      std::cerr << "Error: Invalid value '" << tokens[2] << "'" << std::endl;
    }
    return;
  }

  // Set the variable
  vars[tokens[1]] = std::stoi(tokens[2]);

  if (is_debug) {
    std::cout << "Variable '" << tokens[1] << "' set to " << tokens[2] << std::endl;
  }
}

