#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

// AC
// In place version using reversal.
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    if (0 == k) {
      return;
    }
    // 1 2 3 4
    // 3 4 1 2

    // 4 3 2 1
    reverse(all(nums));

    // 3 4 1 2
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

class Solution_AC2 {
 public:
  void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    if (0 == k) {
      return;
    }

    int start = nums.size() - k;
    // int initialSize = nums.size();
    nums.insert(nums.end(), nums.begin(), nums.end());
    vi ans;
    rep(i, start, nums.size() + start) { ans.push_back(nums[i]); }
    nums = ans;
  }
};

class Solution_AC1 {
 public:
  void rotate(vector<int>& nums, int k) {
    // solve here
    k = k % nums.size();
    if (0 == k) {
      return;
    }

    vector<int> ans;
    for (int i = nums.size() - k; i < nums.size(); ++i) {
      ans.push_back(nums[i]);
    }
    for (int i = 0; i < nums.size() - k; ++i) {
      ans.push_back(nums[i]);
    }

    nums = ans;
  }
};

class Solution_TLE {
 public:
  void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    if (0 == k) {
      return;
    }
    for (int i = 0; i < k; ++i) {
      int t = nums.back();
      for (int j = nums.size() - 2; j >= 0; --j) {
        nums[j + 1] = nums[j];
      }
      nums[0] = t;
    }
  }
};

int main() {
  vi a = {1, 2, 3, 4};
  Solution().rotate(a, 2);
  return 0;
}