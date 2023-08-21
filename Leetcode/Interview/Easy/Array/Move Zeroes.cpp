#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back
#define vi vector<int>
#define mii map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int i = 0;
    // 0 0 0 1 2 3
    for (int j = 0; j < nums.size(); j++) {
      if (nums[j] != 0) {
        // swap(nums[j], nums[i]);
        nums[i] = nums[j];
        i++;
      }
    }
    while(i < sz(nums)) {
        nums[i] = 0;
        ++i;
    }
  }
};

// some one elses code, very fast
class Solution_FAST {
 public:
  void moveZeroes(vector<int>& nums) {
    int i = 0;
    // 0 0 0 1 2 3
    for (int j = 0; j < nums.size(); j++) {
      if (nums[j] != 0) {
        swap(nums[j], nums[i]);
        i++;
      }
    }
  }
};

class Solution_AC_SLOW {
 public:
  void moveZeroes(vi& nums) {
    int lastZero = -1, lastNonZero = -1;
    while (true) {
      // find a zero
      int zi = -1;
      rep(i, 0, sz(nums)) {
        if (0 == nums[i]) {
          zi = i;
          break;
        }
      }
      if (-1 == zi) {
        // no zeros
        break;
      }
      int nzi = -1;
      rep(i, zi + 1, sz(nums)) {
        if (0 != nums[i]) {
          nzi = i;
          break;
        }
      }

      if (-1 == nzi) {
        // no non zeros
        break;
      }
      swap(nums[zi], nums[nzi]);
      /* nums[zi] = nums[nzi];
      nums[nzi] = 0; */
    }
  }
};

int main() {
  vi a = {0, 1, 0, 3, 12};
  Solution().moveZeroes(a);
  return 0;
}
