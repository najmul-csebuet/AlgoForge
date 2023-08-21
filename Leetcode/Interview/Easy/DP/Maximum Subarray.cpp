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

// How it is ac?
class Solution_AC_1 {
 public:
  int maxSubArray(vi& nums) {
    int best = INT_MIN, runningSum = 0;
    tr(nums, a) {
      runningSum += a;
      best = max(best, runningSum);
      runningSum = max(0, runningSum);
    }
    return best;
  }
};

class Solution_AC_2 {
 public:
  int maxSubArray(vi& nums) {
    int best = nums[0], runningSum = nums[0];
    rep(i, 1, sz(nums)) {
      runningSum = max(nums[i], runningSum + nums[i]);
      best = max(best, runningSum);
    }
    return best;
  }
};

int main() {
  // var s = Solution();
  return 0;
}
