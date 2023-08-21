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

class Solution_AC_129_ms {
 public:
  vvi threeSum(vi& nums) {
    vvi ans;
    mii lastIndexMap, firstIndexMap;

    sort(all(nums));

    int n = sz(nums);
    for (int i = 0; i < n; ++i) {
      int a = nums[i];
      lastIndexMap[a] = i;
      if (!firstIndexMap.count(a)) {
        firstIndexMap[a] = i;
      }
    }

    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) break;
      int low = i + 1, high = n - 1;
      while (low < high) {
        int s = nums[i] + nums[low] + nums[high];
        if (s < 0)
          ++low;
        else if (s > 0)
          --high;
        else {
          ans.pb({nums[i], nums[low], nums[high]});
          low = lastIndexMap[nums[low]] + 1;
          high = firstIndexMap[nums[high]] - 1;
        }
      }
      i = lastIndexMap[nums[i]];
    }
    return ans;
  }
};

class Solution_AC_97_ms {
 public:
  vvi threeSum(vi& nums) {
    vvi ans;

    mii countMap;
    tr(nums, a) countMap[a]++;

    sort(all(nums));

    int n = sz(nums);
    for (int i = 0; i < n; i += countMap[nums[i]]) {
      if (nums[i] > 0) break;

      int search = -nums[i];
      // find which 2 numbers sum up to search
      int low = i + 1, high = n - 1;

      while (low < high) {
        int s = nums[low] + nums[high];
        if (s > search) {
          // we need more -ve
          --high;
        } else if (s < search) {
          // we need more +ve
          ++low;
        } else {
          // we found
          ans.pb({nums[i], nums[low], nums[high]});

          // now avoid repeated numbers
          while (low < high) {
            ++low;
            if (nums[low] != nums[low - 1]) {
              break;
            }
          }

          while (low < high) {
            --high;
            if (nums[high] != nums[high + 1]) {
              break;
            }
          }
        }
      }
    }
    return ans;
  }
};

class Solution_AC_SLOW {
 public:
  vvi threeSum(vi& nums) {
    sort(all(nums));

    vvi ans;

    unordered_map<string, bool> taken;

    unordered_map<int, int> count;
    tr(nums, a) count[a]++;

    int n = sz(nums);

    for (int i = 0; i < n; i += count[nums[i]]) {
      for (int j = i + 1; j < n; j += 1) {
        int search = -(nums[i] + nums[j]);

        int c = 1;
        if (search == nums[i]) ++c;
        if (search == nums[j]) ++c;

        if (count[search] < c) {
          continue;
        }

        vi triple = {nums[i], nums[j], search};
        sort(all(triple));
        string key =
            to_string(triple[0]) + to_string(triple[1]) + to_string(triple[2]);
        if (taken[key]) {
          continue;
        }
        taken[key] = true;
        ans.pb(triple);
      }
    }
    return ans;
  }
};

class Solution_TLE_3 {
 public:
  vvi threeSum(vi& nums) {
    sort(all(nums));

    vvi ans;
    int n = sz(nums);

    set<string> keySet;

    unordered_map<int, bool> mp;
    tr(nums, a) mp[a] = true;

    rep(i, 0, n) {
      rep(j, i + 1, n) {
        int search_nums_k = -(nums[i] + nums[j]);
        if (!mp[search_nums_k]) {
          continue;
        }

        vi t = {nums[i], nums[j], search_nums_k};
        sort(all(t));
        string key = to_string(t[0]) + to_string(t[1]) + to_string(t[2]);
        if (keySet.find(key) == keySet.end()) {
          ans.pb({nums[i], nums[j], search_nums_k});
          keySet.insert(key);
        }
      }
    }
    return ans;
  }
};

class Solution_TLE_2 {
 public:
  vvi threeSum(vi& nums) {
    sort(all(nums));

    vvi ans;
    int n = sz(nums);
    map<string, bool> mp;

    rep(i, 0, n) {
      rep(j, i + 1, n) {
        int search_nums_k = -(nums[i] + nums[j]);
        var found =
            binary_search(nums.begin() + j + 1, nums.end(), search_nums_k);
        if (!found) {
          continue;
        }

        vi t = {nums[i], nums[j], search_nums_k};
        sort(all(t));
        string key = to_string(t[0]) + to_string(t[1]) + to_string(t[2]);
        if (!mp[key]) {
          ans.pb({nums[i], nums[j], search_nums_k});
          mp[key] = true;
        }
      }
    }
    return ans;
  }
};

class Solution_TLE_1 {
 public:
  vvi threeSum(vi& nums) {
    vvi ans;
    map<string, bool> mp;

    int n = sz(nums);
    rep(i, 0, n) {
      rep(j, i + 1, n) {
        rep(k, j + 1, n) {
          if (nums[i] + nums[j] + nums[k] == 0) {
            vi t = {nums[i], nums[j], nums[k]};
            sort(all(t));
            string key = to_string(t[0]) + to_string(t[1]) + to_string(t[2]);
            if (!mp[key]) {
              ans.pb({nums[i], nums[j], nums[k]});
              mp[key] = true;
            }
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  vi d = {-1, -1, 0, 1};
  // var s = Solution();
  // var r = s.threeSum(d);
  return 0;
}
