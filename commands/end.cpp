// end.cpp

#include <iostream>
#include <string>

// Definition of the tok_end function
void tok_end(const std::string &line, const bool is_debug) {
  if (is_debug) {
    std::cout << "End of code reached" << std::endl;
  }
  exit(0);
}

