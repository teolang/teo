#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>

// Definition of the tok_for function
void tok_for(const std::string &line, const std::map<std::string, int> &vars,
             const bool is_debug) {
  // Split the line into tokens
  std::istringstream iss(line);
  std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                  std::istream_iterator<std::string>{}};

  if (tokens.size() != 5) {
    if (is_debug) {
      std::cerr << "Error: Invalid number of arguments for 'for' command"
                << std::endl;
    }
    return;
  }

  // Check if the start, end, and step variables exist
  if (vars.find(tokens[1]) == vars.end() || vars.find(tokens[3]) == vars.end() ||
      vars.find(tokens[4]) == vars.end()) {
    if (is_debug) {
      std::cerr << "Error: Unknown variable in 'for' command" << std::endl;
    }
    return;
  }

  // Get the start, end, and step variables
  int start = vars.at(tokens[1]);
  int end = vars.at(tokens[3]);
  int step = vars.at(tokens[4]);

  // Loop from start to end with the specified step
  for (int i = start; i <= end; i += step) {
    if (is_debug) {
      std::cout << "Current value: " << i << std::endl;
    }
  }
}

