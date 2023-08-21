#include <bits/stdc++.h>
using namespace std;

/* Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4] */

// AC
class Solution1 {
 public:
  void rotate(vector<int>& nums, int k) {
    // no rotation needed
    if (0 == k) return;

    // take modulas to reduce the work
    k = k % nums.size();

    vector<int> ans;
    int i = nums.size() - k;
    while (i < nums.size()) {
      ans.push_back(nums[i]);
      ++i;
    }

    i = 0;
    while (i < (nums.size() - k)) {
      ans.push_back(nums[i]);
      ++i;
    }
    nums = ans;
  }
};

// AC
class Solution2 {
 public:
  void rotate(vector<int>& nums, int k) {
    // no rotation needed
    if (0 == k) return;

    // take modulas to reduce the work
    k = k % nums.size();

    vector<int> ans(nums);
    ans.insert(ans.end(), nums.begin(), nums.end());
    int i = nums.size() - k;
    for (int j = 0; j < nums.size(); ++j, ++i) {
      nums[j] = ans[i];
    }
  }
};

// TLE
class Solution3 {
 public:
  void rotate(vector<int>& nums, int k) {
    // no rotation needed
    if (0 == k) return;

    // take modulas to reduce the work
    k = k % nums.size();

    while (k-- > 0) {
      int t = nums.back();
      for (int i = nums.size() - 1; i > 0; --i) {
        nums[i] = nums[i - 1];
      }

      nums[0] = t;
    }
  }
};

// AC

// [  1 2 3    4 5 6 7 ]
// [  7 6 5    4 3 2 1 ]
// [ -------  ---------]
// [  5 6 7    1 2 3 4 ]
class Solution4 {
 public:
  void rotate(vector<int>& nums, int k) {
    // no rotation needed
    if (0 == k) return;

    // take modulas to reduce the work
    k = k % nums.size();

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + 6, nums.end());
  }
};

int main() {
  // Solution().solve();
  return 0;
}
