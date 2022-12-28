// interpret.cpp

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "assert.cpp"
#include "end.cpp"
#include "goto.cpp"
#include "let.cpp"
#include "print.cpp"

#include "cparse/shunting-yard.h"

enum commandlist {
  Let,
  Print,
  Goto,
  Assert,
  End,
};

// Definition of the interpret function
void interpret(const std::vector<std::string> &code_lines,
               const bool is_debug) {
  cparse::TokenMap vars;
  std::map<std::string, commandlist> commands;
  commands["let"] = Let;
  commands["print"] = Print;
  commands["goto"] = Goto;
  commands["assert"] = Assert;
  commands["end"] = End;
  int current_line = 0;
  bool gotoed = false;
  while (current_line < code_lines.size()) {
    gotoed = false;
    const auto &line = code_lines[current_line];
    std::stringstream ss(line);
    std::string command;
    ss >> command;
    std::cout << "Running '" << line << "'" << std::endl;
    std::map<std::string, commandlist>::iterator commandit =
        commands.find(command);
    if (commandit == commands.end()) {
      std::cerr << "Command not found!" << std::endl;
      exit(1);
    } else {
      switch (commandit->second) {
      case Let:
        tok_let(line, vars, is_debug);
        break;
      case Print:
        tok_print(line, vars, is_debug);
        break;
      case Goto:
        tok_goto(line, code_lines, current_line, vars, is_debug);
        gotoed = true;
        break;
      case Assert:
        if (tok_if(line, vars, is_debug) != -1) {
          tok_goto("goto " + std::to_string(tok_if(line, vars, is_debug)),
                   code_lines, current_line, vars, is_debug);
          gotoed = true;
        }
        break;
      case End:
        tok_end(line, is_debug);
        break;
      }
    }
    /*
    if (line.find("let ") == 0) {
      // Call the tok_let function defined in the let.cpp file
      tok_let(line, vars, is_debug);
    } else if (line.find("print ") == 0) {
      // Call the tok_print function defined in the print.cpp file
      tok_print(line, vars, is_debug);
    } else if (line.find("goto ") == 0) {
      // Call the tok_goto function defined in the goto.cpp file
      // Pass a reference to the code_lines and current_line variables
      tok_goto(line, code_lines, current_line, vars, is_debug);
      gotoed = true;
    } else if (line.find("assert ") == 0) {
      if (tok_if(line, vars, is_debug) != -1) {
        tok_goto("goto " + std::to_string(tok_if(line, vars, is_debug)),
                 code_lines, current_line, vars, is_debug);
        gotoed = true;
      }
    } else if (line.find("end") == 0) {
      // Call the tok_end function defined in the end.cpp file
      tok_end(line, is_debug);
    } else {
      if (is_debug) {
        std::cerr << "Error: Unknown command '" << line << "'" << std::endl;
      }
    }
    */
    // Increment the current_line variable unless it was set by the tok_goto
    // function
    if (!gotoed) {
      current_line++;
    }
  }
}
