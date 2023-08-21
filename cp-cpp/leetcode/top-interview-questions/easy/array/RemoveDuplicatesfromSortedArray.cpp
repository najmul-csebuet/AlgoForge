#include <bits/stdc++.h>
using namespace std;

// Accepted

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    int i, j;
    for (i = 0, j = 1; j < nums.size(); ++j) {
      if (nums[i] < nums[j]) {
        nums[++i] = nums[j];
      }
    }
    return i + 1;
  }
};

int main() {
  // Solution().solve();
  return 0;
}
