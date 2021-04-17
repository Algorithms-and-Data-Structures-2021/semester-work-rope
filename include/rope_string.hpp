#pragma once

// Заголовочный файл с объявлением структуры данных

#include <string>
#include <list>

using std::string;

namespace itis {

  struct Node {
    ~Node(void);
    void print_tree(std::ostream&, unsigned int);

    const char* fragment;
    Node *left, *right;
    int weight;
  };

  struct Rope {
   public:
    Rope(const string&);
    ~Rope(void);

    typedef string::value_type CharT;

    CharT at(unsigned int);
    void insert(unsigned int, const char*);
    void insert(unsigned int, const string&);
    unsigned int length(void) const;

    void print_tree(std::ostream&);

    void copy(char*, unsigned int) const;
    void consolidate(void);

    void update_weights(Node*) const;
    unsigned int internal_copy(Node*, char*, unsigned int) const;
    unsigned int weight_sum(Node*) const;

    Node* root;

    std::list<const char*> to_delete;
  };

}  // namespace itis