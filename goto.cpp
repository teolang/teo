#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "cparse/shunting-yard.h"

void tok_goto(const std::string &line,
              const std::vector<std::string> &code_lines, int &current_line, cparse::TokenMap vars,
              const bool is_debug) {
  // Extract the label specified after the "goto " keyword
  std::string label = line.substr(5);
  int it = cparse::calculator::calculate(label.c_str(), &vars).asInt();
  if (it <= code_lines.size()) {
    if (is_debug) {
      std::cout << "Going to line '" << label << "'" << std::endl;
    }
    // If the line is found, set the current_line variable to the index of the
    // line
    current_line = it - 1;
  } else {
    // If the line is not found, print an error message if debug mode is enabled
    if (is_debug) {
      std::cerr << "Error: Unknown label '" << label << "'" << std::endl;
    }
  }
}
