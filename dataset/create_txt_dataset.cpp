#include <fstream>
#include <iostream>
#include <rope_string.hpp>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace itis;

void create_data_for_insert_merge(string path, int x) {
  ofstream fout;
  fout.open(path);

  char a[26] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd',
                'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'b', 'v', 'c', 'x', 'z'};

  if (x < 5000) {
    this_thread::sleep_for(std::chrono::nanoseconds(700000000));
  }
  srand(time(nullptr));

    for (int j = 0; j < x/2; j++) {
      int c = rand() % 25;
      fout << a[c];
    }
    fout << " ";
    for (int j = 0; j < x/2; j++) {
      int c = rand() % 25;
      fout << a[c];
    }
    fout.close();
}

void create_data_for_split_delete_find(string path, int x) {
  ofstream fout;
  fout.open(path);

  char a[26] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd',
                'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'b', 'v', 'c', 'x', 'z'};

  if(!fout.is_open()){
    cout << "Error" << endl;
  } else {
    if (x < 5000) {
      this_thread::sleep_for(std::chrono::nanoseconds(700000000));
    }
    srand(time(nullptr));
    for (int j = 0; j < x; j++) {
      int c = rand() % 25;
      fout << a[c];
    }
  }
  fout.close();
}

int main(){
  string path = "dataset/data";
  int a[14] = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 750000, 1000000, 2500000, 5000000};
  ofstream fout;
  for (int j = 0; j < 14; ++j) {
    for (int k = 1; k < 11; ++k) {
      string s1 = to_string(a[j]);
      string s2 = to_string(k);
      create_data_for_split_delete_find(path + "/find_split_delete/" + s1 + "(" + s2 + ").txt", a[j]);
      create_data_for_insert_merge(path + "/insert_merge/" + s1 + "(" + s2 + ").txt", a[j]);
    }
  }

  return 0;
}