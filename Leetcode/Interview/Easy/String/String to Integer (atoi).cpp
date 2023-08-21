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
  pair<bool, string> getNumberString(string& s) {
    string sn;
    // skip spaces
    int i;
    for (i = 0; i < sz(s); ++i) {
      if (' ' != s[i]) {
        break;
      }
    }
    // now check if +/- is present or not
    bool positive = true;
    if ('-' == s[i]) {
      positive = false;
    }

    if (s[i] == '+' || s[i] == '-') {
      ++i;
    }

    rep(j, i, sz(s)) {
      if (isdigit(s[j])) {
        sn.pb(s[j]);
      } else {
        break;
      }
    }
    return {positive, sn};
  }

  int myAtoi(string s) {
    pair<bool, string> p = getNumberString(s);
    bool positive = p.first;
    string sn = p.second;
    int ans = 0;
    tr(sn, c) {
      int d = c - '0';
      if (positive) {
        if (ans > (INT_MAX - d) / 10) {
          return INT_MAX;
        }
        ans = ans * 10 + d;
      } else {
        if (ans < (INT_MIN + d) / 10) {
          return INT_MIN;
        }
        ans = ans * 10 - d;
      }
    }
    return ans;
  }
};

int main() {
  var s = Solution();
  int a = s.myAtoi("-2147483648");
  return 0;
}
