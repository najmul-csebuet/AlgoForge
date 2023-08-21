#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define mii map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

#define tr(container, it) \
  for (auto it = container.begin(); it != container.end(); it++)
#define trr(container, it) \
  for (auto it = container.rbegin(); it != container.rend(); it++)

// Assume Both input is sorted
// how can we improve our algo
// Merge algo approach
class Solution {
 public:
  vi intersect(vi& nums1, vi& nums2) {
    sort(all(nums1));
    sort(all(nums2));
    // 1 1 2 2 3
    // 2 2
    vi ans;
    int i = 0, j = 0;
    while (i < sz(nums1) && j < sz(nums2)) {
      if (nums1[i] < nums2[j]) {
        ++i;
        continue;
      }

      if (nums1[i] > nums2[j]) {
        ++j;
        continue;
      }

      ans.pb(nums1[i]);
      ++i;
      ++j;
    }

    return ans;
  }
};

class Solution_AC_MAP {
 public:
  vi intersect(vi& nums1, vi& nums2) {
    vi ans;
    mii count;

    // biuld count info from nums1

    tr(nums1, a) { count[*a]++; }
    tr(nums2, a) {
      if (count[*a] > 0) {
        count[*a]--;
        ans.pb(*a);
      }
    }

    /* rep(i, 0, sz(nums1)) { count[nums1[i]]++; }
    rep(i, 0, sz(nums2)) {
      if (count[nums2[i]] > 0) {
        --count[nums2[i]];
        ans.pb(nums2[i]);
      }
    } */
    return ans;
  }
};

class Solution_AC_SLOW {
 public:
  vi intersect(vi& nums1, vi& nums2) {
    vi taken(sz(nums1));
    vi ans;
    rep(i, 0, sz(nums2)) {
      rep(j, 0, sz(nums1)) {
        if (nums1[j] == nums2[i] && taken[j] == 0) {
          taken[j] = 1;
          ans.pb(nums2[i]);
          break;
        }
      }
    }
    return ans;
  }
};

int main() {
  vi a = {1, 2, 2, 1};
  vi b = {2, 2};
  vi ans = {2, 2};
  vi res = Solution_AC_SLOW().intersect(a, b);
  if (ans == res) {
    cout << "PASS\n";
  } else {
    cout << "Fail\n";
  }
  return 0;
}
