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
 public:
  bool increasingTriplet(vi& nums) {
    vi minIndex(sz(nums));
    minIndex[0] = 0;
    rep(i, 1, sz(nums)) {
      if (nums[i - 1] < nums[i]) {
        minIndex[i] = i - 1;
      } else if (nums[i - 1] == nums[i]) {
        minIndex[i] = minIndex[i - 1];
      } else {
        // nums[i - 1] > nums[i]
        if (nums[minIndex[i - 1]] < nums[i]) {
          minIndex[i] = minIndex[i - 1];
        } else {
          minIndex[i] = i;
        }
      }
    }

    for (int i = sz(nums) - 1; i >= 0; --i) {
      if (minIndex[i] == i) {
        continue;
      }
      int earlierMinIndex = minIndex[i];
      if (minIndex[earlierMinIndex] == earlierMinIndex) {
        continue;
      }
      // we found a triplet
      return true;
    }
    return false;
  }
};

int main() {
  var s = Solution();
  vi v = {20, 100, 10, 12, 5, 13};
  s.increasingTriplet(v);
  return 0;
}
