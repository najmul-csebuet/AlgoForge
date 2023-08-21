#include <bits/stdc++.h>
using namespace std;

#define var auto
#define endl '\n'

#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define fill(v, c) memset(v, c, sizeof(v))

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

/*
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

// AC
class Solution1 {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    rep(i, 0, sz(nums)) {
      rep(j, i + 1, sz(nums)) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }

    return {};
  }
};

// AC
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;

    rep(i, 0, sz(nums)) {
      if (m[target - nums[i]] > 0) {
        return {i, m[target - nums[i]] - 1};
      }
      m[nums[i]] = i + 1;
    }

    return {};
  }
};

int main() {
  vector<int> v = {2, 7, 11, 15};
  Solution().twoSum(v, 9);
  return 0;
}

/*
class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i<nums.size(); i++)
        {
            if(mp.find(target - nums[i]) == mp.end())
                mp[nums[i]] = i;
            else
                return {mp[target - nums[i]], i};
        }
        return {0,0};
    }

    int binSearch(vector<pair<int, int>>& nums, int l, int r, int s) {
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int v = nums[mid].first;
            if(v == s) {
                return mid;
            }

            if(v < s) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // not found
        return -1;
    }

    vector<int> twoSum1(vector<int>& nums, int target) {

        // Input: nums = [2,7,11,15], target = 9
        // Output: [0,1]

        vector<pair<int, int>> pairs;
        for(int i = 0; i < nums.size(); ++i) {
            pairs.push_back({nums[i], i});
        }
        sort(pairs.begin(), pairs.end());
        vector<int> ans;
        for(int i = 0; i < pairs.size(); ++i) {
            int a = target - pairs[i].first;
            int res = binSearch(pairs, 0, pairs.size() - 1, a);
            if(res == -1 || res == i) continue;
            ans.push_back(pairs[i].second);
            ans.push_back(pairs[res].second);
            break;
        }
        return ans;
    }
};
*/