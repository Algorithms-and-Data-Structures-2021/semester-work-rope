#include <iostream>
#include <cstring>

#include "rope_string.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  const string str = "Hello, World!!";
  const string other = "Lewin";

  itis::Rope r(str);
  r.insert(5, other);
  r.insert(6, other);
  r.insert(7, other);
  r.insert(13, other);
  r.insert(55, str);
  r.print_tree(std::cout);

  char *buf = new char[128];
  r.copy(buf,127);


  std::cout << buf << std::endl << std::endl;

 for (unsigned int i = 0; i < r.length(); i++)
   std::cout << r.get_char(i);

 cout << endl;

  return 0;
}