#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define si set<int>

#define pii pair<int, int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class Solution_AC_FAST {
 public:
  int firstUniqChar(string s) {
    int m[26] = {0};
    tr(s, a) { m[a - 'a']++; }
    rep(i, 0, sz(s)) {
      if (m[s[i] - 'a'] == 1) {
        return i;
      }
    }
    return -1;
  }
};

class Solution_AC_Complex {
 public:
  int firstUniqChar(string s) {
    map<int, pii> count;
    rep(i, 0, sz(s)) {
      count[s[i]].first++;
      count[s[i]].second = i;
    }
    vector<pii> v;
    tr(count, a) { v.pb(a.second); }
    sort(all(v));
    if (v[0].first > 1) {
      return -1;
    }
    return v.front().second;
  }
};

int main() {
  Solution().firstUniqChar("leetcode");
  return 0;
}
