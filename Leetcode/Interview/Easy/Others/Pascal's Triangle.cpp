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
  vvi generate(int numRows) {
    vvi ans;
    vi temp = {1};
    rep(r, 0, numRows) {
      vi next = {temp.front()};
      rep(i, 0, sz(temp) - 1) { next.pb(temp[i] + temp[i + 1]); }
      if (r > 0) {
        next.pb(temp.back());
      }
      ans.pb(next);
      temp = next;
    }
    return ans;
  }
};

int main() {
  var s = Solution();
  return 0;
}
