#include <bits/stdc++.h>
using namespace std;

#define var auto
#define str string
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
  void permuteRecursive(vi& nums, vector<bool>& flag, vvi& ans, vi& perm) {
    if (sz(perm) == sz(nums)) {
      ans.push_back(perm);
      return;
    }

    rep(i, 0, sz(nums)) {
      if (flag[i]) continue;
      // take ith item
      perm.pb(nums[i]);
      flag[i] = true;
      permuteRecursive(nums, flag, ans, perm);
      flag[i] = false;
      perm.pop_back();
    }
  }

 public:
  vvi permute(vi& nums) {
    vector<bool> flag(sz(nums));
    vvi ans;
    vi perm;
    permuteRecursive(nums, flag, ans, perm);
    return ans;
  }
};

class Solution1 {
 public:
  vvi permute(vi& nums) {
    vvi ans;
    sort(all(nums));
    do {
      ans.pb(nums);
    } while (next_permutation(all(nums)));
    return ans;
  }
};

void testCase1() {
  // var s = Solution();
}

int main() {
  testCase1();
  return 0;
}
