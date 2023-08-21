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

class Solution_AC {
 public:
  void merge(vi& nums1, int m, vi& nums2, int n) {
    // scan from at the end
    // find the largest number and
    // place it at the end of nums1
    // clever!
    int i = m - 1, j = n - 1, k = sz(nums1) - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] >= nums2[j]) {
        nums1[k] = nums1[i];
        --i;
      } else {
        nums1[k] = nums2[j];
        --j;
      }
      --k;
    }

    while (i >= 0) {
      nums1[k] = nums1[i];
      --i;
      --k;
    }

    while (j >= 0) {
      nums1[k] = nums2[j];
      --j;
      --k;
    }
  }
};

int main() {
  var s = Solution();
  return 0;
}
