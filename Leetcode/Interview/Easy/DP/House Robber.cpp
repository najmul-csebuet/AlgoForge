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
  int rob(vi& nums) {
    int n = sz(nums);
    if (n == 1) {
      return nums[0];
    }

    int rm_i_2 = 0, rm_i_1 = nums[0];
    rep(i, 2, n + 1) {
      int temp = max(rm_i_1, nums[i - 1] + rm_i_2);
      rm_i_2 = rm_i_1;
      rm_i_1 = temp;
    }

    return rm_i_1;
  }
};

class Solution_AC {
 public:
  int rob(vi& nums) {
    int n = sz(nums);
    if (n == 1) {
      return nums[0];
    }

    vi robbedMoney(n + 1, 0);
    robbedMoney[0] = 0;
    robbedMoney[1] = nums[0];
    rep(i, 2, n + 1) {
      robbedMoney[i] =
          max(robbedMoney[i - 1], nums[i - 1] + robbedMoney[i - 2]);
    }
    return robbedMoney[n];
  }
};

int main() {
  var s = Solution();
  return 0;
}
