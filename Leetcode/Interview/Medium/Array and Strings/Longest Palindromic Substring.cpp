#include <bits/stdc++.h>
using namespace std;

#define var auto
#define str string
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define si set<int>
#define mii map<int, int>
#define pii pair<int, int>
#define umii unordered_map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class Solution_AC_DP {
  int getLen(pii p) { return p.second - p.first + 1; }

 public:
  str longestPalindrome(str s) {
    int n = sz(s);
    bool dp[n][n];
    pii maxPair = {0, 0};

    rep(i, 0, n) { dp[i][i] = true; }

    rep(i, 0, n - 1) {
      dp[i][i + 1] = s[i] == s[i + 1];
      if (dp[i][i + 1]) maxPair = {i, i + 1};
    }

    rep(len, 3, n + 1) {
      rep(left, 0, n - len + 1) {
        int right = left + len - 1;
        dp[left][right] = dp[left + 1][right - 1] && s[left] == s[right];
        if (dp[left][right]) {
          maxPair = {left, right};
        }
      }
    }

    return s.substr(maxPair.first, getLen(maxPair));
  }
};

// AC -- Wow how?
class Solution_AC_2 {
  pair<int, int> maxPalin(str& s, int left, int right) {
    int len = sz(s);
    while (left >= 0 && right < len) {
      if (s[left] != s[right]) {
        ++left;
        --right;
        break;
      }
      if (left == 0 || right == len - 1) {
        break;
      }
      --left;
      ++right;
    }
    return {left, right};
  }
  int getLen(pair<int, int> p) { return p.second - p.first + 1; }

 public:
  str longestPalindrome(str s) {
    // remember to give valid initial values to variables always
    // I think default varies compiler to compiler. So do not ignore it to
    // initialize
    int len = sz(s), L = 0, R = 0;

    rep(mid, 0, len) {
      var odd = maxPalin(s, mid, mid);
      var even = maxPalin(s, mid, mid + 1);

      var range = getLen(odd) > getLen(even) ? odd : even;

      if (getLen(range) > getLen({L, R})) {
        L = range.first;
        R = range.second;
      }
    }

    str ans = s.substr(L, R - L + 1);
    return ans;
  }
};

class Solution_AC {
  pair<int, int> getMaxPalinLen(str& s, int left, int right) {
    int len = sz(s);
    while (left >= 0 && right < len) {
      if (s[left] != s[right]) {
        ++left;
        --right;
        break;
      }
      if (left == 0 || right == len - 1) {
        break;
      }
      --left;
      ++right;
    }
    return {left, right};
  }

 public:
  str longestPalindrome(str s) {
    int len = sz(s), L = len, R = -1;

    // check odd length palindrome
    rep(mid, 0, len) {
      var range = getMaxPalinLen(s, mid, mid);
      int left = range.first;
      int right = range.second;
      if (right - left > R - L) {
        L = left;
        R = right;
      }
    }

    // check even length palindrome
    rep(mid, 0, len) {
      var range = getMaxPalinLen(s, mid, mid + 1);
      int left = range.first;
      int right = range.second;
      if (right - left > R - L) {
        L = left;
        R = right;
      }
    }

    str ans = s.substr(L, R - L + 1);
    return ans;
  }
};

class Solution_Wrong {
  bool isPalindrome(str s) {
    str t = s;
    reverse(all(t));
    return t == s;
  }

 public:
  str longestPalindrome(str s) {
    str curr = "", maxPalin = "";
    rep(right, 0, sz(s)) {
      curr += s[right];
      while (!isPalindrome(curr)) {
        curr.erase(0);
      }
      if (sz(curr) > sz(maxPalin)) {
        maxPalin = curr;
      }
    }
    return maxPalin;
  }
};

int main() {
  var s = Solution();
  /* var ans1 = s.longestPalindrome("babad");
  var ans2 = s.longestPalindrome("cbbd"); */
  var ans2 = s.longestPalindrome("ccc");
  return 0;
}
