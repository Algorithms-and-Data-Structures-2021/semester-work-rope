#pragma once

// Заголовочный файл с объявлением структуры данных

#include <string>
#include <list>

using std::string;

namespace itis {

  struct Node {
    //деструктор вершины
    ~Node(void);
    //конструктор вершины
    Node(void);

    void print_tree(std::ostream&, unsigned int);

    const char* fragment;
    Node *left, *right;
    int weight;
    unsigned char height;
  };

  unsigned char height(Node* node);
  int bfactor(Node* node);
  void fix_height(Node* node);

  struct Rope {
   public:
    //конструктор rope
    Rope(const string&);
    //деструктор rope
    ~Rope(void);

    void print_tree(std::ostream&);

    typedef string::value_type CharT;
    //вывод строки
    CharT get_char(unsigned int);
    //добавление строки
    void insert(unsigned int, const string&);
    unsigned int length(void) const;

    //копирование часть строки из rope в переменную
    void copy(char*, unsigned int) const;

    Node* rotate_right(Node* node);
    Node* rotate_left(Node* node);
    Node* balance(Node* node);

    void update_weights(Node*) const;
    unsigned int internal_copy(Node*, char*, unsigned int) const;
    unsigned int weight_sum(Node*) const;

    Node* root;
    //вектор, хранящий ссылки на строки для дальнейшего удаления, чтобы не было утечки памяти
    std::list<const char*> to_delete;
  };

}  // namespace itis