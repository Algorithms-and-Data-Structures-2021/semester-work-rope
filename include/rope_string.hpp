#pragma once

// Заголовочный файл с объявлением структуры данных

#include <string>
#include <stack>

using std::string;

namespace itis {

  struct Node {
    char key;
    long long size; // количество узлов ниже (включая себя)
    Node* left;
    Node* right;
    Node* parent;
    Node(char key, long long size, Node* left, Node* right, Node* parent);
  };

  struct Rope {
    std::string s;
    Node* root;

   public:
    //Преобразует строку в структуру Rope
    Rope(const std::string& s);

    //Удаление структуры Rope
    ~Rope(void);

    //Вспомогательный метод, обновляет размер, задаёт родительский узел для левого и правого узла
    void update(Node* v);

    //Используется для балансировки дерева
    void small_rotation(Node* v);

    //Используется для балансировки дерева
    void big_rotation(Node* v);

    //
    void splay(Node*& root, Node* v);

    //
    Node* find(Node*& root, int leftNum);

    //
    void split(Node* root, int key, Node*& left, Node*& right);

    //
    Node* merge(Node* left, Node* right);

    //
    void insert(Node*& root, int k, Node*& subString);

    //
    std::string traversal_in_order(Node* root);

    //
    std::string result();
  };

}  // namespace itis