#include "../cparse/shunting-yard.h"
#include <iostream>
#include <string>

int tok_if(const std::string &line, cparse::TokenMap vars,
           const bool is_debug) {
  std::string commands = line.substr(7);
  size_t pos = commands.find_last_of(' ');
  // Extract the first part of the string up to the last space
  std::string assertion = commands.substr(0, pos);
  // Extract the last word by finding the position of the first character after
  // the last space
  std::string goifassert = commands.substr(pos + 1);

  if (cparse::calculator::calculate(assertion.c_str(), &vars) == 1) {
    if (is_debug) {
      std::cout << "Assertion success, running 'goto " << goifassert << "'"
                << std::endl;
    }
    return stoi(goifassert);
  } else {
    if (is_debug) {
      std::cout << "Assertion failed" << std::endl;
    }
  }
  return -1;
}
