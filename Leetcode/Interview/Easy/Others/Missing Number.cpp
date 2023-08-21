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
  int missingNumber(vi& nums) {
    int n = sz(nums);
    int ans = n * (n + 1) / 2;
    int sum = 0;
    tr(nums, a) sum += a;
    return ans - sum;
  }
};

int main() {
  var s = Solution();
  return 0;
}
