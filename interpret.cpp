// interpret.cpp

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "end.cpp"
#include "goto.cpp"
#include "let.cpp"
#include "print.cpp"

// Definition of the interpret function
void interpret(const std::vector<std::string> &code_lines,
               const bool is_debug) {
  std::map<std::string, int> vars{};
  int current_line = 0;
  while (current_line < code_lines.size()) {
    const auto &line = code_lines[current_line];
    if (line.find("let ") == 0) {
      // Call the tok_let function defined in the let.cpp file
      tok_let(line, vars, is_debug);
    } else if (line.find("print ") == 0) {
      // Call the tok_print function defined in the print.cpp file
      tok_print(line, vars, is_debug);
    } else if (line.find("goto ") == 0) {
      // Call the tok_goto function defined in the goto.cpp file
      // Pass a reference to the code_lines and current_line variables
      tok_goto(line, vars, code_lines, current_line, is_debug);
    } else if (line.find("end") == 0) {
      // Call the tok_end function defined in the end.cpp file
      tok_end(line, is_debug);
    } else {
      if (is_debug) {
        std::cerr << "Error: Unknown command '" << line << "'" << std::endl;
      }
    }
    // Increment the current_line variable unless it was set by the tok_goto function
      current_line++;
  }
}

