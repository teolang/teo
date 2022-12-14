#include <iostream>
#include <map>
#include <sstream>
#include <string>

int tok_assert(const std::string &line, std::map<std::string, int> &vars,
               const bool is_debug) {
  std::string commands = line.substr(7);
  std::stringstream ss(commands);
  std::string variable[2];
  std::string goifassert;
  std::getline(ss, variable[0], ' ');
  std::getline(ss, variable[1], ' ');
  std::getline(ss, goifassert);
  if (vars.find(variable[0]) == vars.end() ||
      vars.find(variable[1]) == vars.end()) {
    if (is_debug) {
      std::cerr << "Error: Unknown variable '" << variable[0] << "'"
                << std::endl;
    }
  } else {
    if (vars.at(variable[0]) == vars.at(variable[1])) {
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
  }
  return -1;
}
