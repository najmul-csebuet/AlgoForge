#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    rep(i, 0, sz(nums)) ans ^= nums[i];
    return ans;
  }
};

int main() {
  // Solution().solve();
  return 0;
}
