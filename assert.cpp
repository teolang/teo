#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include "cparse/shunting-yard.h"

int tok_assert(const std::string &line, cparse::TokenMap vars,
               const bool is_debug) {
  std::string commands = line.substr(7);
  std::stringstream ss(commands);
  std::string variable[2];
  std::string goifassert;
  std::getline(ss, variable[0], ' ');
  std::getline(ss, variable[1], ' ');
  std::getline(ss, goifassert);

    if (vars[variable[0]] == vars[variable[1]]) {
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
