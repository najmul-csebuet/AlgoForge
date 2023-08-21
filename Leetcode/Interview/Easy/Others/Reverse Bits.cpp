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
  uint32_t reverseBits(uint32_t n) {
    vi list;
    rep(i, 0, 32) {
      int a = n & 1;
      list.pb(a);
      n >>= 1;
    }
    uint32_t ans = 0;
    rep(i, 0, 32) { ans = ans | (list[i] << (31 - i)); }
    return ans;
  }
};

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;

    rep(i, 0, 32) {
      ans <<= 1;
      ans = ans | (n & 1);
      n >>= 1;
    }

    return ans;
  }
};

int main() {
  var s = Solution();
  var ans = s.reverseBits(1 << 31);
  return 0;
}
