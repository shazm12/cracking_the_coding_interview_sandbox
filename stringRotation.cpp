#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool stringRotation1(string s, string g) {
  if (s.length() != g.length()) {
    return false;
  }

  string startingRot = "";
  string endingRot = "";
  int j = 0;
  while (j < s.length() && s[0] != g[j]) {
    j++;
  }
  startingRot = g.substr(j);
  endingRot = g.substr(0, j);
  string finalString = startingRot + endingRot;
  if (finalString == s) {
    return true;
  }

  return false;
}

bool stringRotation2(string s, string g) {
  if (s.length() != g.length()) {
    return false;
  }
  string doubleS = s + s;
  if (doubleS.find(g)) {
    return true;
  }
  return false;
}

int main() {
  cout << stringRotation1("waterbottle", "crbottlewat") << endl;
  return 0;
}