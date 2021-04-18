#include <iostream>
#include <cstring>

#include "rope_string.hpp"

using namespace std;

int main() {
  std::string s = "Rizvan was here";
  itis::Rope rope(s);
  cout << rope.find(rope.root, 6)->key << endl;
  std::cout << rope.result() << std::endl;

  return 0;
}