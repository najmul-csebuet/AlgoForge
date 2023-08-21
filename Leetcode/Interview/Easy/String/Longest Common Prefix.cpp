#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back
#define vi vector<int>
#define vs vector<string>
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
  string longestCommonPrefix(vs& strs) {
    string ans = "";
    int minLen = INT_MAX;
    tr(strs, a) {
      if (sz(a) < minLen) {
        minLen = sz(a);
      }
    }
    int lcp = 0;
    rep(i, 0, minLen) {
      bool matched = true;
      rep(j, 0, sz(strs) - 1) {
        if (strs[j][i] != strs[j + 1][i]) {
          i = minLen;
          matched = false;
          break;
        }
      }
      if (matched) ++lcp;
    }
    rep(i, 0, lcp) { ans.pb(strs[0][i]); }
    return ans;
  }
};

int main() {
  vs v = {"flower", "flow", "flight"};
  var s = Solution().longestCommonPrefix(v);
  return 0;
}
