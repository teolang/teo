// interpret.cpp

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// Declarations for the functions defined in the let.cpp, print.cpp, and end.cpp
// files
extern void tok_let(const std::string &line, std::map<std::string, int> &vars,
                    const bool is_debug);
extern void tok_print(const std::string &line,
                      const std::map<std::string, int> &vars,
                      const bool is_debug);
extern void tok_end(const std::string &line, const bool is_debug);

// Definition of the interpret function
void interpret(const std::vector<std::string> &code_lines, const bool is_debug) {
  std::map<std::string, int> vars{};

  for (const auto &line : code_lines) {
    if (line.find("let ") == 0) {
      // Call the tok_let function defined in the let.cpp file
      tok_let(line, vars, is_debug);
    } else if (line.find("print ") == 0) {
      // Call the tok_print function defined in the print.cpp file
      tok_print(line, vars, is_debug);
    } else if (line.find("end") == 0) {
      // Call the tok_end function defined in the end.cpp file
      tok_end(line, is_debug);
    } else {
      if (is_debug) {
        std::cerr << "Error: Unknown command '" << line << "'" << std::endl;
      }
    }
  }
}

