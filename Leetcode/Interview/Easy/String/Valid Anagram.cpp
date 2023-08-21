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
  bool isAnagram(string s, string t) {
    if (sz(s) != sz(t)) {
      return false;
    }

    int map[127] = {0};
    tr(s, a) { map[a]++; }
    tr(t, a) { map[a]--; }
    tr(map, a) {
      if (a != 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  var s = Solution();
  return 0;
}
