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
  int climbStairs(int n) {
    vi a(n + 1, 0);  // (n + 1) 0 values
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; ++i) {
      a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
  }
};

int main() {
  var s = Solution();
  return 0;
}
