#include "rope_string.hpp"

namespace itis {
  Node::Node(char key, long long size, Node* left, Node* right, Node* parent)
      : key(key), size(size), left(left), right(right), parent(parent) {}

  Rope::Rope(const std::string& s) : s(s) {
    root = NULL;
    for (int i = 0; i < s.length(); i++) {
      Node* next = new Node(s[i], 1, NULL, NULL, NULL);
      root = merge(root, next);
    }
  }

  Rope::~Rope(void)
  {
    if ( root )
      delete root;
  }

  Node::~Node(void)
  {
    if ( left )
      delete left;
    if ( right )
      delete right;
  }

  void Rope::update(Node* v) {
    if (v == NULL)
      return;
    v->size = 1 + (v->left != NULL ? v->left->size : 0) + (v->right != NULL ? v->right->size : 0);
    if (v->left != NULL) {
      v->left->parent = v;
    }
    if (v->right != NULL) {
      v->right->parent = v;
    }
  }

  void Rope::small_rotation(Node* v) {
    Node* parent = v->parent;
    if (parent == NULL) {
      return;
    }
    Node* grandparent = v->parent->parent;
    if (parent->left == v) {
      Node* m = v->right;
      v->right = parent;
      parent->left = m;
    } else {
      Node* m = v->left;
      v->left = parent;
      parent->right = m;
    }
    update(parent);
    update(v);
    v->parent = grandparent;
    if (grandparent != NULL) {
      if (grandparent->left == parent) {
        grandparent->left = v;
      } else {
        grandparent->right = v;
      }
    }
  }

  void Rope::big_rotation(Node* v) {
    if (v->parent->left == v && v->parent->parent->left == v->parent) {
      small_rotation(v->parent);
      small_rotation(v);
    } else if (v->parent->right == v && v->parent->parent->right == v->parent) {
      small_rotation(v->parent);
      small_rotation(v);
    } else {
      small_rotation(v);
      small_rotation(v);
    }
  }
  void Rope::splay(Node*& root, Node* v) {
    if (v == NULL)
      return;
    while (v->parent != NULL) {
      if (v->parent->parent == NULL) {
        small_rotation(v);
        break;
      }
      big_rotation(v);
    }
    root = v;
  }

  Node* Rope::find(Node*& root, int leftNum)
  {
    Node* v = root;

    while (v != NULL) {
      long long s = (v->left != NULL) ? v->left->size : 0;
      if (leftNum == (s + 1)) {
        break;
      }
      else if (leftNum < (s + 1)) {
        v = v->left;
      }
      else if (leftNum > (s + 1)) {
        v = v->right;
        leftNum = leftNum - s - 1;
      }
    }
    splay(root, v);
    return v;
  }

  void Rope::split(Node* root, int key, Node*& left, Node*& right)
  {
    right = find(root, key);
    splay(root, right);
    if (right == NULL) {
      left = root;
      return;
    }
    left = right->left;
    right->left = NULL;
    if (left != NULL) {
      left->parent = NULL;
    }
    update(left);
    update(right);
  }

  Node* Rope::merge(Node* left, Node* right)
  {
    if (left == NULL)
      return right;
    if (right == NULL)
      return left;
    Node* min_right = right;
    while (min_right->left != NULL) {
      min_right = min_right->left;
    }
    splay(right, min_right);
    right->left = left;
    update(right);
    return right;
  }

  void Rope::insert(Node*& root, int k, Node*& subString)
  {
    Node* left = NULL;
    Node* right = NULL;
    split(root, k, left, right);
    root = merge(merge(left, subString), right);
  }

  std::string Rope::traversal_in_order(Node* root)
  {
    std::string printS = "";
    if (root == NULL) {
      return printS;
    }
    std::stack<Node*> S;
    Node* p = root;

    while (p != NULL) {
      S.push(p);
      p = p->left;
    }

    while (!S.empty()) {
      p = S.top();
      printS.push_back(p->key);
      S.pop();
      p = p->right;
      while (p != NULL) {
        S.push(p);
        p = p->left;
      }
    }
    return printS;
  }

  std::string Rope::result()
  {
    s = traversal_in_order(root);
    return s;
  }
}  // namespace itis