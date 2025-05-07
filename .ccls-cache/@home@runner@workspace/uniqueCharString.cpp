
#include <iostream>
using namespace std;

bool uniqueCharString(string str) {
  if (str.length() > 128) {
    return false;
  }
  bool char_set[128];
  int i;
  for (i = 0; i < str.length(); i++) {
    int char_val = str[i];
    if (char_set[char_val]) {
      return false;
    }
    char_set[char_val] = true;
  }
  return true;
}
