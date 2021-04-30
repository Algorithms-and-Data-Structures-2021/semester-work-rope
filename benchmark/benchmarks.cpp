#include <fstream>
#include <chrono>
#include <rope_string.hpp>
#include <iostream>

using namespace std;
using namespace itis;

static constexpr auto kProjectPath = string_view{PROJECT_DATASET_DIR};

void time_for_merge(int x, int a) {
  const auto path = string(kProjectPath);
  ifstream fin;
  string num_of_incoming_data = to_string(x);
  string set_num = to_string(a);
  for (int i = 0; i < 10; i++) {
    fin.open(path + "/insert_merge/" + num_of_incoming_data + "(" + set_num + ").txt");
    if (!fin.is_open()) {
      cout << "Error" << endl;
    } else {
      string str;
      fin >> str;
      Rope rope1(str);
      fin >> str;
      Rope rope2(str);

      const auto time_point_before = chrono::high_resolution_clock::now();
      rope1.merge(rope1.root, rope2.root);
      const auto time_point_after = chrono::high_resolution_clock::now();

      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      cout << "time wasted to merge two strings in file " + num_of_incoming_data + "(" + set_num + ").txt "
           << time_elapsed_ns << '\n';
      rope1.free_tree(rope1.root);
    }
    fin.close();
  }
}

void time_for_insert(int x, int a) {
  const auto path = string(kProjectPath);
  ifstream fin;
  string num_of_incoming_data = to_string(x);
  string set_num = to_string(a);
  for (int i = 0; i < 10; i++) {
    fin.open(path + "/insert_merge/" + num_of_incoming_data + "(" + set_num + ").txt");
    if (!fin.is_open()) {
      cout << "Error" << endl;
    } else {
      int c = rand() % x;
      string str;
      fin >> str;
      Rope rope1(str);
      fin >> str;
      Rope rope2(str);

      const auto time_point_before = chrono::high_resolution_clock::now();
      rope1.insert(rope1.root, c, rope2.root);
      const auto time_point_after = chrono::high_resolution_clock::now();

      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      cout << "time wasted to insert one string to second string in file " + num_of_incoming_data + "(" + set_num
                  + ").txt "
           << time_elapsed_ns << '\n';
      rope1.free_tree(rope1.root);
    }
    fin.close();
  }
}

void time_for_find(int x, int a) {
  const auto path = string(kProjectPath);
  ifstream fin;
  string num_of_incoming_data = to_string(x);
  string set_num = to_string(a);
  for (int i = 0; i < 10; i++) {
    fin.open(path + "/find_split_delete/" + num_of_incoming_data + "(" + set_num + ").txt");
    if (!fin.is_open()) {
      cout << "Error" << endl;
    } else {
      int c = rand() % x;
      string str;
      fin >> str;
      Rope rope(str);

      const auto time_point_before = chrono::high_resolution_clock::now();
      rope.find(rope.root, c);
      const auto time_point_after = chrono::high_resolution_clock::now();

      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      cout << "time wasted to find symbol in file " + num_of_incoming_data + "(" + set_num + ").txt " << time_elapsed_ns
           << '\n';
      rope.free_tree(rope.root);
    }
    fin.close();
  }
}

void time_for_split(int x, int a) {
  const auto path = string(kProjectPath);
  ifstream fin;
  string num_of_incoming_data = to_string(x);
  string set_num = to_string(a);
  for (int i = 0; i < 10; i++) {
    fin.open(path + "/find_split_delete/" + num_of_incoming_data + "(" + set_num + ").txt");
    if (!fin.is_open()) {
      cout << "Error" << endl;
    } else {
      int c = rand() % x;
      string str;
      fin >> str;
      Rope rope(str);
      Node *node1;
      Node *node2;

      const auto time_point_before = chrono::high_resolution_clock::now();
      rope.split(rope.root, c, node1, node2);
      const auto time_point_after = chrono::high_resolution_clock::now();

      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      cout << "time wasted to split string in file " + num_of_incoming_data + "(" + set_num + ").txt "
           << time_elapsed_ns << '\n';
      rope.free_tree(node1);
      rope.free_tree(node2);
    }
    fin.close();
  }
}

void time_for_delete(int x, int a) {
  const auto path = string(kProjectPath);
  ifstream fin;
  string num_of_incoming_data = to_string(x);
  string set_num = to_string(a);
  for (int i = 0; i < 10; i++) {
    fin.open(path + "/find_split_delete/" + num_of_incoming_data + "(" + set_num + ").txt");
    if (!fin.is_open()) {
      cout << "Error" << endl;
    } else {
      int c = rand() % (x - 2);
      int k = rand() % (x - c - 1);
      k = k + c;
      string str;
      fin >> str;
      Rope rope(str);

      const auto time_point_before = chrono::high_resolution_clock::now();
      rope.delete_substr(rope.root, c, k);
      const auto time_point_after = chrono::high_resolution_clock::now();

      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      cout << "time wasted to delete substring in file " + num_of_incoming_data + "(" + set_num + ").txt "
           << time_elapsed_ns << '\n';
      rope.free_tree(rope.root);
    }
    fin.close();
  }
}

int main() {
  int arr[14] = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 750000, 1000000, 2500000, 5000000};
  for (int i = 0; i < 14; i++) {
    for (int j = 1; j < 11; j++) {
      time_for_insert(arr[i], j);
      time_for_merge(arr[i], j);
      time_for_find(arr[i], j);
      time_for_split(arr[i], j);
      time_for_delete(arr[i], j);
    }
  }

  return 0;
}