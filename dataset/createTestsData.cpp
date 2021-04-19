#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int createData(string str, int x) {
  ofstream fout;
  fout.open(str);

  char a[26] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd',
                'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'b', 'v', 'c', 'x', 'z'};


  srand(time(NULL));
  for(int i=0; i<x; i++){
    int b = rand()%30;
    b++;
    fout << (i+1) << ", ";
    for(int j = 0; j<b; j++){
      int c = rand()%25;
      fout << a[c];
    }
    fout << "\n";
  }
  return 0;
}