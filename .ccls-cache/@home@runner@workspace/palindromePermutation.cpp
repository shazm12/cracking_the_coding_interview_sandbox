#include <bits/stdc++.h>
#include <iostream>
using namespace std;

unordered_map<char, int> buildFreqMap(string s) {

  unordered_map<char, int> map;
  int i;
  for (i = 0; i < s.length(); i++) {
    map[s[i]]++;
  }
  return map;
}

bool checkIfPalindrome(unordered_map<char, int> map) {

  bool foundOddChar = false;

  for (auto it : map) {
    if (it.second % 2 == 1) {
      if (foundOddChar) {
        return false;
      } else {
        foundOddChar = true;
      }
    }
  }

  return true;
}

int main() {
  // Write C++ code here
  string s = "brorobot";
  unordered_map<char, int> freqMap = buildFreqMap(s);
  bool res = checkIfPalindrome(freqMap);
  cout << res;
  return 0;
}