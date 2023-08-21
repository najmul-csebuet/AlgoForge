#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back
#define vi vector<int>
#define mii map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class Solution_AC_Without_Extra_Memory {
 public:
  vi plusOne(vi& digits) {
    var cin = 1;
    // 1 2 3 4
    reverse(all(digits));
    // 4 3 2 1
    tr(digits, a) {
      var t = cin + a;
      a = t % 10;
      cin = t / 10;
    }
    if (cin > 0) digits.pb(cin);
    reverse(all(digits));

    return digits;
  }
};

class Solution_AC_Extra_Memory {
 public:
  vi plusOne(vi& digits) {
    vi ans;
    var cin = 1;
    // 1 2 3 4
    reverse(all(digits));
    // 4 3 2 1
    tr(digits, a) {
      var t = cin + a;
      a = t % 10;
      ans.pb(a);
      cin = t / 10;
    }
    if (cin > 0) ans.pb(cin);
    reverse(all(ans));
    return ans;
  }
};

class Solution1 {
 public:
  int solve() {
    // solve here
    return 0;
  }
};

int main() {
  vi v = {1, 2, 3};
  vi ans = Solution_AC_Without_Extra_Memory().plusOne(v);
  cout << ans[2] << endl;
  return 0;
}
