#include <bits/stdc++.h>
using namespace std;

#define A true
#ifdef A

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

#endif

class Solution_AC_Cascading {
 public:
  vvi subsets(vi& nums) {
    vi temp;
    vvi ans = {temp};

    tr(nums, a) {
      vvi tempAnsList;
      tr(ans, b) {
        vi bCopy = b;
        bCopy.pb(a);
        tempAnsList.pb(bCopy);
      }
      tr(tempAnsList, a) { ans.pb(a); }
    }
    return ans;
  }
};

class Solution_AC_Direct_Iteration {
 public:
  vvi subsets(vi& nums) {
    vvi ans;
    int n = sz(nums);
    int totalSubsets = pow(2, n);

    rep(i, 0, totalSubsets) {
      // 0 -- 000
      // 1 -- 001
      // 2 -- 010
      // 3 -- 011
      vi ar;
      rep(j, 0, n) {
        var a = 1 << j;
        var b = i & a;
        if (b != 0) {
          // take n - j + 1 index number from nums
          ar.pb(nums[n - j - 1]);
        }
      }

      ans.pb(ar);
    }

    return ans;
  }
};

void testCase1() {
  var s = Solution_AC_Direct_Iteration();
  vi ar = {1, 2, 3};
  var ans = s.subsets(ar);
}

void testCase2() {
  var s = Solution_AC_Cascading();
  vi ar = {1, 2, 3};
  var ans = s.subsets(ar);
}

int main() {
  testCase1();
  return 0;
}
