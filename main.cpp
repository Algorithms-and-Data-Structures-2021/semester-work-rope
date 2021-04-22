#include <iostream>
#include "rope_string.hpp"

using namespace std;

int main(){
  std::string s = "Rizvan was here";
  itis::Rope rope(s);
  cout << rope.find(rope.root, 6)->key << endl;
  std::cout << rope.result() << std::endl;
  std::string s1 = "n't";
  itis::Rope rope1(s1);
  rope.insert(rope.root, 11, rope1.root);
  std::cout << rope.result() << std::endl;
  rope.delete_substr(rope.root, 11, 13);
  std::cout << rope.result() << std::endl;
  return 0;
}