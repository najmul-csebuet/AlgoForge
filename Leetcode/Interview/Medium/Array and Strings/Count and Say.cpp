#include <bits/stdc++.h>
using namespace std;

#define var auto
#define str string
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

//AC
class Solution {
 public:
  str countAndSay(int n) {
    if (n == 1) {
      return "1";
    }
    str n_1 = countAndSay(n - 1) + '$';

    //"1211$"
    int c = 0;
    str ans = "";
    rep(i, 0, sz(n_1) - 1) {
      ++c;
      if (n_1[i] != n_1[i + 1]) {
        ans += to_string(c) + n_1[i];
        c = 0;
      }
    }
    return ans;
  }
};

int main() {
  var s = Solution();
  var ans = s.countAndSay(4);
  cout << ans << endl;
  return 0;
}
