#include "rope_string.hpp"

namespace itis {
  Node::Node(char key, long long size, Node* left, Node* right, Node* parent)
      : key(key), size(size), left(left), right(right), parent(parent) {}

  Rope::Rope(const std::string& s) : s(s) {
    root = nullptr;
    for (int i = 0; i < s.length(); i++) {
      Node* next = new Node(s[i], 1, nullptr, nullptr, nullptr);
      root = merge(root, next);
    }
  }

  void Rope::update(Node* v) {
    if (v == nullptr)
      return;
    v->size = 1 + (v->left != nullptr ? v->left->size : 0) + (v->right != nullptr ? v->right->size : 0);
    if (v->left != nullptr) {
      v->left->parent = v;
    }
    if (v->right != nullptr) {
      v->right->parent = v;
    }
  }

  void Rope::small_rotation(Node* v) {
    Node* parent = v->parent;
    if (parent == nullptr) {
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
    if (grandparent != nullptr) {
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
    if (v == nullptr)
      return;
    while (v->parent != nullptr) {
      if (v->parent->parent == nullptr) {
        small_rotation(v);
        break;
      }
      big_rotation(v);
    }
    root = v;
  }

  void Rope::delete_substr(Node*& root, int startIndex, int endIndex) {
    Node *node1 = nullptr;
    Node *node2 = nullptr;
    split(root, startIndex, root, node1);
    split(node1, endIndex - startIndex + 1, node1, node2);
    root = merge(root, node2);
    free_tree(node1);
  }

  Node* Rope::find(Node*& root, int leftNum) {
    Node* v = root;

    while (v != nullptr) {
      long long s = (v->left != nullptr) ? v->left->size : 0;
      if (leftNum == (s + 1)) {
        break;
      } else if (leftNum < (s + 1)) {
        v = v->left;
      } else if (leftNum > (s + 1)) {
        v = v->right;
        leftNum = leftNum - s - 1;
      }
    }
    splay(root, v);
    return v;
  }

  void Rope::split(Node* root, int key, Node*& left, Node*& right) {
    right = find(root, key);
    splay(root, right);
    if (right == nullptr) {
      left = root;
      return;
    }
    left = right->left;
    right->left = nullptr;
    if (left != nullptr) {
      left->parent = nullptr;
    }
    update(left);
    update(right);
  }

  Node* Rope::merge(Node* left, Node* right) {
    if (left == nullptr)
      return right;
    if (right == nullptr)
      return left;
    Node* min_right = right;
    while (min_right->left != nullptr) {
      min_right = min_right->left;
    }
    splay(right, min_right);
    right->left = left;
    update(right);
    return right;
  }

  void Rope::insert(Node*& root, int k, Node*& subString) {
    Node* left = nullptr;
    Node* right = nullptr;
    split(root, k, left, right);
    root = merge(merge(left, subString), right);
  }

  std::string Rope::traversal_in_order(Node* root) {
    std::string printS = "";
    if (root == nullptr) {
      return printS;
    }
    std::stack<Node*> S;
    Node* p = root;

    while (p != nullptr) {
      S.push(p);
      p = p->left;
    }

    while (!S.empty()) {
      p = S.top();
      printS.push_back(p->key);
      S.pop();
      p = p->right;
      while (p != nullptr) {
        S.push(p);
        p = p->left;
      }
    }
    return printS;
  }

  std::string Rope::result() {
    s = traversal_in_order(root);
    return s;
  }

  void Rope::free_tree(Node* node) {
    if (node != nullptr) {
      Rope::free_tree(node->left);
      Rope::free_tree(node->right);
      delete node;
    }
  }
}  // namespace itis