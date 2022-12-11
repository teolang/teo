#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void tok_goto(const std::string &line, std::map<std::string, int> &vars,
              const std::vector<std::string> &code_lines, int &current_line,
              const bool is_debug) {
  // Parse the line to extract the label to go to
  std::string label =
      line.substr(5); // 5 is the length of "goto "
                      // The label was found in the code, so set the
                      // current_line variable to the line number of the label
  current_line = std::stoi(label);
  if (is_debug) {
    std::cout << "Going to line " << label << " : " << code_lines[std::stoi(label)] << std::endl;
  }
}
