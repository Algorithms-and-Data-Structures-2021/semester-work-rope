//
// Created by HP on 24.04.2021.
//

#include <iostream>
#include "../include/rope_string.hpp"

using namespace std;

int main(){
  std::string s = "I was here";
  //создание структуры данных
  itis::Rope rope(s);
  std::cout << rope.result() << std::endl;
  //поиск символа
  cout << rope.find(rope.root, 7)->key << endl;

  std::string s1 = "n't";
  itis::Rope rope1(s1);
  //вставка подстроки
  rope.insert(rope.root, 6, rope1.root);
  std::cout << rope.result() << std::endl;
  //удаление подстроки
  rope.delete_substr(rope.root, 6, 9);
  std::cout << rope.result() << std::endl;

  itis::Rope rope2("");
  itis::Rope rope3("");
  //разделение на 2 дерева
  rope.split(rope.root, 6, rope2.root, rope3.root);
  std::cout << rope2.result() << std::endl;
  std::cout << rope3.result() << std::endl;
  //слияние 2 деревьев
  rope.root = rope2.merge(rope2.root, rope3.root);
  std::cout << rope.result() << std::endl;
  return 0;
}
