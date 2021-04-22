#include <fstream>
#include <chrono>
#include <rope_string.hpp>
#include <iostream>
#include <random>

using namespace std;
using namespace itis;

static constexpr auto kProjectPath = string_view{PROJECT_DATASET_DIR};

void time_for_merge(int x, int a) {
  const auto path = string(kProjectPath);
  ifstream fin;
  string string1 = to_string(x);
  string s = to_string(a);
  for (int i = 0; i < 10; i++) {
    fin.open(path + "/insert_merge/" + string1 + "(" + s + ").txt");
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

      cout << time_elapsed_ns << '\n';
    }
    fin.close();
  }
}

void time_for_insert(int x, int a) {
  const auto path = string(kProjectPath);
  ifstream fin;
  string string1 = to_string(x);
  string s = to_string(a);
  for (int i = 0; i < 10; i++) {
    fin.open(path + "/insert_merge/" + string1 + "(" + s + ").txt");
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

      cout << time_elapsed_ns << '\n';
    }
    fin.close();
  }
}

void time_for_find(int x, int a) {
  const auto path = string(kProjectPath);
  ifstream fin;
  string string1 = to_string(x);
  string s = to_string(a);
  for (int i = 0; i < 10; i++) {
    fin.open(path + "/find_split_delete/" + string1 + "(" + s + ").txt");
    if (!fin.is_open()) {
      cout << "Error" << endl;
    } else {
      int c = rand() % x;
      string str;
      fin >> str;
      Rope rope1(str);
      const auto time_point_before = chrono::high_resolution_clock::now();
      rope1.find(rope1.root, c);
      const auto time_point_after = chrono::high_resolution_clock::now();

      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      cout << time_elapsed_ns << '\n';
    }
    fin.close();
  }
}

void time_for_split(int x, int a) {
  const auto path = string(kProjectPath);
  ifstream fin;
  string string1 = to_string(x);
  string s = to_string(a);
  for (int i = 0; i < 10; i++) {
    fin.open(path + "/find_split_delete/" + string1 + "(" + s + ").txt");
    if (!fin.is_open()) {
      cout << "Error" << endl;
    } else {
      int c = rand() % x;
      string str;
      fin >> str;
      Rope rope1(str);
      Node *node1;
      Node *node2;
      const auto time_point_before = chrono::high_resolution_clock::now();
      rope1.split(rope1.root, c, node1, node2);
      const auto time_point_after = chrono::high_resolution_clock::now();

      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      cout << time_elapsed_ns << '\n';
    }
    fin.close();
  }
}

void time_for_delete(int x, int a) {
  const auto path = string(kProjectPath);
  ifstream fin;
  string string1 = to_string(x);
  string s = to_string(a);
  for (int i = 0; i < 10; i++) {
    fin.open(path + "/find_split_delete/" + string1 + "(" + s + ").txt");
    if (!fin.is_open()) {
      cout << "Error" << endl;
    } else {
      int c = rand() % (x-2);
      int k = rand() % (x-c-1);
      k=k+c;
      string str;
      fin >> str;
      Rope rope1(str);
      const auto time_point_before = chrono::high_resolution_clock::now();
      rope1.delete_substr(rope1.root, c, k);
      const auto time_point_after = chrono::high_resolution_clock::now();

      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      cout << time_elapsed_ns << '\n';
    }
    fin.close();
  }
}

int main() {
  int arr[14] = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 750000, 1000000, 2500000, 5000000};
  for (int i = 0; i < 14; i++) {
    for (int j = 1; j < 11; j++) {
      /*
       *time_for_insert(arr[i], j);
      time_for_merge(arr[i], j);
      time_for_find(arr[i], j);
      time_for_split(arr[i], j);
       */
      time_for_delete(arr[i],j);
    }
  }


  return 0;
}