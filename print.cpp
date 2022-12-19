#include "cparse/shunting-yard.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <sstream>
#include <string>

// Definition of the tok_print function
void tok_print(const std::string &line, cparse::TokenMap vars,
               const bool is_debug) {
  // Split the line into tokens
  std::istringstream iss(line);
  std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                  std::istream_iterator<std::string>{}};

  if (tokens.size() != 2) {
    if (is_debug) {
      std::cerr << "Error: Invalid number of arguments for 'print' command"
                << std::endl;
    }
    return;
  }

  // Print the variable
  std::cout << cparse::calculator::calculate(tokens[1].c_str(), &vars).asDouble() << std::endl;
}

