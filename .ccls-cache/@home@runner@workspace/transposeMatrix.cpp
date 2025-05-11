#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>> mat, int n) {
  vector<vector<int>> res(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[j][i] = mat[i][j];
    }
  }

  return res;
}

int main() {
  vector<vector<int>> input = {{10, 20, 30}, {40, 50, 20}, {20, 10, 40}};
  int n = 3;
  vector<vector<int>> ans = transpose(input, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}