#include "rope_string.hpp"
#include "iostream"

namespace itis {

  // Выводит строку в консоль
  void Node::print(Node *node) {
    // Если передан пустой узел, то ничего не происходит. Останавливает рекурсию.
    if (node == nullptr)
      return;

    // Если узел является конечным в данном дереве, то выводится подстрока, которую он содержит
    if (node->left == nullptr && node->right == nullptr)
      std::cout << node->str;

    // Вызывается рекурсивная функция для левого и правого узлов
    print(node->left);
    print(node->right);
  }

  // Соединяет две строки в третью. n1 и n2 - узлы которые необходимо объединить в узел n3, int l - кол-во символов char в узле n1, который будет слева от n3
  void Node::concatenate(Node *n1, Node *n2, Node *n3, int l) {
    n3->parent = nullptr;

    // Сообщается, что 1 узел будет слева от родительского узла, а 2 узел справа
    n3->left = n1;
    n3->right = n2;

    // Сообщается, что 3 узел будет родителем двух других
    n1->parent = n3;
    n2->parent = n3;

    // Сообщается, что слева от конечного узла будет находится l символов
    n3->lCount = l;
  }

  // Разделяет строку по некоторому индексу. Левая часть остается в изначальном узле, вторая возвращается
  Node Node::split(Node *n1, int index) {
    Node n2;
  }

}  // namespace itis