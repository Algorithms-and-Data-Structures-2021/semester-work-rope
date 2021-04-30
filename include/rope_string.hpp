#pragma once

// Заголовочный файл с объявлением структуры данных

#include <string>
#include <stack>
#include <list>

using std::string;

namespace itis {

  struct Node {
    char key;
    long long size;  // количество узлов ниже (включая себя)
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
    void free_tree(Node *node);

    //Вспомогательный метод, обновляет размер, задаёт родительский узел для левого и правого узла
    void update(Node* v);

    //Используется для балансировки дерева
    void small_rotation(Node* v);

    //Используется для балансировки дерева
    void big_rotation(Node* v);

    //удаление подстроки
    void delete_substr(Node*& root, int startIndex, int endIndex);

    //использует для балансировки дерева, нод v становится root
    void splay(Node*& root, Node* v);

    //поиск символа по индексу
    Node* find(Node*& root, int leftNum);

    //разделение на 2 дерева по индексу
    void split(Node* root, int key, Node*& left, Node*& right);

    //слияние 2 деревьев
    Node* merge(Node* left, Node* right);

    //вставка строки по индексу
    void insert(Node*& root, int k, Node*& subString);

    //обход вершин по порядку
    std::string traversal_in_order(Node* root);

    //вывод строки
    std::string result();
  };

}  // namespace itis