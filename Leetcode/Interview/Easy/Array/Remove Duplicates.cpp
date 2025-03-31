#include <bits/stdc++.h>
using namespace std;

#define var auto
#define endl '\n'

#define vi vector<int>

#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define fill(v, c) memset(v, c, sizeof(v))

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

// AC
class Solution {
 public:
  int removeDuplicates(vi& nums) {
    var last = 0;
    rep(current, 1, sz(nums)) {
      if (nums[last] != nums[current]) {
        nums[++last] = nums[current];
      }
    }
    return last + 1;
  }
};

int main() {
  // var ans = Solution().solve();
  return 0;
}
