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
  int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    int left = 0;
    vi charIndex(128, -1);  // act as a simple map
    rep(right, 0, sz(s)) {
      int last = charIndex[s[right]];
      if (last >= left) {
        // so this char appears already in the current substring
        // start a new substring after that last index of current char
        left = last + 1;
      }
      charIndex[s[right]] = right;
      maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
  }
};

class Solution_AC_1 {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }

    int maxLen = 1;
    int l = 0, r = 0;
    set<char> uniqueChecker{s[0]};

    rep(i, 1, sz(s)) {
      while (uniqueChecker.count(s[i])) {
        // old char
        uniqueChecker.erase(s[l]);
        ++l;
      }

      if (uniqueChecker.empty()) {
        l = i;
      }

      r = i;
      uniqueChecker.insert(s[i]);
      maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
  }
};

int main() {
  var s = Solution();
  var ans = s.lengthOfLongestSubstring("au");
  return 0;
}
