#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool oneEdit(string s, string t) {
  if (abs((int)s.length() - (int)t.length()) > 1) {
    return false;
  }

  // Longer String
  string s1 = s.length() < t.length() ? t : s;
  // Shorter String
  string s2 = s.length() < t.length() ? s : t;

  int idx1, idx2;
  bool isDifferent = false;
  while (idx1 < s1.length() && idx2 < s2.length()) {

    if (s1[idx1] != s2[idx2]) {
      if (isDifferent) {
        return false;
      } else {
        isDifferent = true;
      }

      if (s1.length() == s2.length()) {
        idx1++;
        idx2++;
      } else {
        idx2++;
      }
    } else {
      idx1++;
      idx2++;
    }
  }
  return true;
}

int main() {
  // Write C++ code here
  string s = "ales";
  string t = "pales";
  cout << oneEdit(s, t) << endl;
  return 0;
}
