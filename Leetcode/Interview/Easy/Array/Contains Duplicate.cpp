#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
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
  // Solution().solve();
  return 0;
}
