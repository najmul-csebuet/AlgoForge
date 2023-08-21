#include <bits/stdc++.h>
using namespace std;

#define var auto
#define endl '\n'

#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define fill(v, c) memset(v, c, sizeof(v))

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

// AC
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> s(all(nums));
    return sz(s) != sz(nums);
  }
};

int main() {
  // var ans = Solution().solve();
  return 0;
}
