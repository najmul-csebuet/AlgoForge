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
  int reverse(int x) {
    bool isNegative = x < 0;
    x = abs(x);
    int ans = 0;
    while (x > 0) {
      int safeLimit = (INT_MAX - x % 10) / 10;
      if (ans > safeLimit) {
        return 0;
      }
      ans = ans * 10 + x % 10;
      x = x / 10;
    }
    if (isNegative) {
      ans = -ans;
    }
    return ans;
  }
};

int main() {
  int a = -123 % 10;
  var s = Solution();
  return 0;
}
