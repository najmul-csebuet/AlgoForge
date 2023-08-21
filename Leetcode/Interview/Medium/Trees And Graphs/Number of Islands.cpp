#include <bits/stdc++.h>
using namespace std;

#define var auto
#define str string
#define pb push_back
#define vi vector<int>
#define vc vector<char>
#define vvi vector<vi>
#define vvc vector<vc>
#define si set<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

// AC
class Solution {
  void fill(vvc& grid, int i, int j) {
    if (i < 0 || j < 0) return;
    if (i >= sz(grid) || j >= sz(grid[i])) return;
    // valid cell
    if (grid[i][j] != '1') return;
    grid[i][j] = '0';
    fill(grid, i - 1, j);
    fill(grid, i + 1, j);
    fill(grid, i, j - 1);
    fill(grid, i, j + 1);
  }

 public:
  int numIslands(vvc& grid) {
    int landCount = 0;
    rep(i, 0, sz(grid)) {
      rep(j, 0, sz(grid[i])) {
        if (grid[i][j] != '1') continue;
        // 0 means water / explored
        // mark all adjacent 1 nodes as -1
        ++landCount;
        fill(grid, i, j);
      }
    }
    return landCount;
  }
};

void testCase1() {
  var s = Solution();
  vvc grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
  var ans = s.numIslands(grid);
  cout << ans << endl;
}

int main() {
  testCase1();
  return 0;
}
