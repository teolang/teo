#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

// Definition of the tok_goto function
void tok_goto(const std::string &line,
              std::map<std::string, int> &vars,
              const std::vector<std::string> &code_lines,
              int &current_line,
              const bool is_debug) {
  // Extract the label specified after the "goto " keyword
  std::string label = line.substr(5);

  // Search for a line that starts with the label followed by a colon (":")
  auto it = std::find_if(code_lines.begin(), code_lines.end(),
                         [&label](const std::string &s) {
                           return s.find(label + ":") == 0;
                         });
  if (it != code_lines.end()) {
    // If the line is found, set the current_line variable to the index of the line
    current_line = std::distance(code_lines.begin(), it);
  } else {
    // If the line is not found, print an error message if debug mode is enabled
    if (is_debug) {
      std::cerr << "Error: Unknown label '" << label << "'" << std::endl;
    }
  }
}

