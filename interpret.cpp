// interpret.cpp

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "commands/assert.cpp"
#include "commands/end.cpp"
#include "commands/goto.cpp"
#include "commands/let.cpp"
#include "commands/print.cpp"

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
  while (static_cast<std::vector<std::string>::size_type>(current_line) < code_lines.size()) {
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
    // Increment the current_line variable unless it was set by the tok_goto
    // function
    if (!gotoed) {
      current_line++;
    }
  }
}
