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

class Solution_AC_1 {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    int xx = ceil(round(log(n) / log(3)));
    double xx1 = log(n) / log(3);
    if(abs(xx - xx1) > 0.00001) {
        xx -= 1;
    }
    int ss = pow(3, xx);
    return ss == n;
  }
};

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n < 1) return false;
    int x = log10(INT_MAX) / log10(3);
    return n > 1 && ( (int) pow(3, x) % n) == 0;
  }
};

int main() {
  var s = Solution();
  s.isPowerOfThree(2147483647);
  return 0;
}
