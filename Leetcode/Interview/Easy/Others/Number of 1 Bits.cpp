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

class Solution_AC_1 {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
      if (n & 1 > 0) ++count;
      n >>= 1;
    }
    return count;
  }
};

class Solution_AC_2 {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
      ++count;
      n = n & (n - 1);
    }
    return count;
  }
};

class Solution_AC_3 {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
      ++count;
      int rmsb = n & (-n);
      n -= rmsb;
    }
    return count;
  }
};

int main() {
  // var s = Solution();
  return 0;
}
