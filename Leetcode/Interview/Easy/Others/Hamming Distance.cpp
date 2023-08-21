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

class Solution_AC {
 public:
  int hammingDistance(int x, int y) {
    // 1010
    // 1100
    // xor
    // 0 1 1 0
    // count set bits
    // done
    int z = x ^ y;
    int c = 0;
    while (z > 0) {
      ++c;
      z = z & (z - 1);
    }
    return c;
  }
};

class Solution_AC_2 {
 public:
  int hammingDistance(int x, int y) {
    // 1010
    // 1100
    // xor
    // 0 1 1 0
    // count set bits
    // done
    return __builtin_popcount(x ^ y);
  }
};

int main() {
  // var s = Solution();
  return 0;
}
