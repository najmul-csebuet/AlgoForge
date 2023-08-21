#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define si set<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class Solution {
 public:
  void rotate(vvi& matrix) {
    int N = sz(matrix);
    if (1 == N) {
      return;
    }

    int n = N - 1;

    rep(r, 0, N / 2) {
      int internalN = N - 2 * r;
      rep(i, 0, internalN - 1) {
        int c = r + i;
        int temp = matrix[r][c];
        rep(k, 0, 4) {
          swap(temp, matrix[c][n - r]);
          int oldR = r;
          r = c;
          c = n - oldR;
        }
      }
    }
  }
};

void printMatrix(vvi& a) {
  rep(i, 0, sz(a)) {
    rep(j, 0, sz(a[0])) { cout << a[i][j] << " "; }
    cout << endl;
  }
  cout << endl;
}

void doWork(vvi& a) {
  printMatrix(a);
  Solution().rotate(a);
  printMatrix(a);
}

int main() {
  vvi a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  doWork(a);
  a = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  doWork(a);
  return 0;
}
