#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back

#define vi vector<int>
#define vc vector<char>
#define vvc vector<vc>

#define si set<int>
#define sc set<char>

#define mii map<int, int>
#define umii unordered_map<int, int>

#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class Solution {
  bool hasRepit(vc chars) {
    vc filtered;
    tr(chars, a) {
      if ('.' != a) {
        filtered.pb(a);
      }
    }
    sc s(all(filtered));
    return sz(s) != sz(filtered);
  }

  bool hasRepitInGrid(vvc& board, int rowStart) {
    vvc grids(3);
    rep(r, rowStart, rowStart + 3) {
      rep(i, 0, 9) {
        // 0,1,2 --> 0
        // 3,4,5 --> 1
        // 6,7,8 --> 2
        int index = i / 3;
        grids[index].pb(board[r][i]);
      }
    }
    rep(i, 0, 3) {
      if (hasRepit(grids[i])) {
        return true;
      }
    }
    return false;
  }

 public:
  bool isValidSudoku(vvc& board) {
    // check every row
    rep(i, 0, sz(board)) {
      if (hasRepit(board[i])) {
        return false;
      }
    }

    // check every col
    rep(c, 0, sz(board[0])) {
      vc v;
      rep(r, 0, sz(board)) { v.pb(board[r][c]); }
      if (hasRepit(v)) {
        return false;
      }
    }

    // check every 3x3 grid
    for (int i = 0; i <= 6; i += 3) {
      if (hasRepitInGrid(board, i)) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  vvc grid = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
              {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
              {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
              {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
              {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
              {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  bool ans = Solution().isValidSudoku(grid);
  return 0;
}
