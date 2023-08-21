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

class Solution {
  vi backup;

 public:
  Solution(vi& nums) { backup = nums; }

  vi reset() { return backup; }

  vi shuffle() {
    vi curr = backup;
    int n = sz(curr);
    rep(i, 0, n - 1) {
      int j = i + rand() % (n - i);
      swap(curr[i], curr[j]);
    }

    return curr;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {
  // var s = Solution();
  return 0;
}
