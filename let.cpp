// let.cpp

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>

#include "cparse/shunting-yard.h"

// Definition of the tok_let function
void tok_let(const std::string &line, cparse::TokenMap vars,
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

  
  // Set the variable
  vars[tokens[1]] = cparse::calculator::calculate(tokens[2].c_str(), &vars).asDouble();

  if (is_debug) {
    std::cout << "Variable '" << tokens[1] << "' set to " << vars[tokens[1]] << std::endl;
  }
}

