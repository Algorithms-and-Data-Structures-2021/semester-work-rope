#include <iostream>
#include <cstring>
#include "rope_string.hpp"
#include "dataset/createTestsData.cpp"

using namespace std;

int main() {
  std::string s = "Rizvan was here";
  itis::Rope rope(s);
  cout << rope.find(rope.root, 6)->key << endl;
  std::cout << rope.result() << std::endl;

  createData("1000.txt", 1000);
  createData("5000.txt", 5000);
  createData("10000.txt", 10000);
  createData("50000.txt", 50000);
  createData("100000.txt", 100000);
  createData("500000.txt", 500000);
  createData("1000000.txt", 1000000);

  return 0;
}