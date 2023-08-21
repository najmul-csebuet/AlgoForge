#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back
#define vi vector<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class Solution {
 public:
  vi twoSum(vi& nums, int target) {
    umii indexMap;

    rep(i, 0, sz(nums)) {
      int partner = target - nums[i];
      if (indexMap.count(partner)) {
        return {indexMap[partner], i};
      }
      indexMap[nums[i]] = i;
    }
    return {};
  }
};

class Solution_AC {
 public:
  vi twoSum(vi& nums, int target) {
    vi ans;
    umii indexMap;

    rep(i, 0, sz(nums)) {
      int partner = target - nums[i];
      if (indexMap.count(partner) == 0) {
        indexMap[nums[i]] = i;
      } else {
        ans = {indexMap[partner], i};
        break;
      }
    }
    return ans;
  }
};

int main() {
  // Solution().solve();
  return 0;
}
