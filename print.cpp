#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <sstream>
#include <string>

// Definition of the tok_print function
void tok_print(const std::string &line, const std::map<std::string, int> &vars,
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

  // Check if the variable exists
  if (vars.find(tokens[1]) == vars.end()) {
    if (is_debug) {
      std::cerr << "Error: Unknown variable '" << tokens[1] << "'" << std::endl;
    }
    return;
  }

  // Print the variable
  std::cout << vars.at(tokens[1]) << std::endl;
}

