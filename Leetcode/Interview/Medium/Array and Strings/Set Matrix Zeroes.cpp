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
  void setZeroes(vvi& matrix) {
    int rowMin = INT_MAX;
    rep(row, 0, sz(matrix)) { rowMin = min(rowMin, matrix[row][0]); }

    if (rowMin <= 0) {
      rep(row, 0, sz(matrix)) { matrix[row][0] += -rowMin + 1; }
    }

    int colMin = INT_MAX;
    rep(col, 0, sz(matrix[0])) { colMin = min(colMin, matrix[col][0]); }
  }
};

int main() {
  var s = Solution();
  return 0;
}
