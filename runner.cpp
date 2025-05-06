#include "hashMap.cpp"
#include <iostream>
using namespace std;

int main() {
  hashMap mp(10);
  mp.insert(1, 2);
  mp.insert(2, 3);

  cout << mp.get(1) << endl;
  cout << mp.get(2) << endl;

  return 0;
}