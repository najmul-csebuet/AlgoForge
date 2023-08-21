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
  int strStr(string haystack, string needle) {
    rep(i, 0, sz(haystack)) {
      var matched = true;
      rep(j, 0, sz(needle)) {
        if (haystack[i + j] != needle[j]) {
          matched = false;
          break;
        }
      }
      if (matched) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  var s = Solution();
  var haystack = "leetcode", needle = "leeto";
  var ans = s.strStr(haystack, needle);
  cout << (ans == 0) << endl;
  return 0;
}
