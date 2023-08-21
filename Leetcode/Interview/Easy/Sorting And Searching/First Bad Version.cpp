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

// The API isBadVersion is defined for you.
bool isBadVersion(int version) { return true; }

class Solution {
 public:
  int firstBadVersion(int n) {
    int l = 1, r = n, ans = n;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (isBadVersion(m)) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
};

class Solution_AC_Good {
 public:
  int firstBadVersion(int n) {
    int l = 1, r = n;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (isBadVersion(m)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};

class Solution_AC_1 {
 public:
  int firstBadVersion(int n) {
    int l = 1, r = n;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (isBadVersion(m)) {
        r = m - 1;
        if (!isBadVersion(r)) {
          return m;
        }
      } else {
        l = m + 1;
      }
    }
    return 1;
  }
};

class Solution_AC_2 {
 public:
  int firstBadVersion(int n) {
    int l = 1, r = n;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (!isBadVersion(m)) {
        l = m + 1;
        if (isBadVersion(l)) {
          return l;
        }
      } else {
        r = m - 1;
      }
    }
    return 1;
  }
};

int main() {
  var s = Solution();
  return 0;
}
