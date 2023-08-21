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

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/*
To convert a sorted integer array into a height-balanced binary search tree, you
can follow a recursive approach. The idea is to select the middle element of the
array as the root of the tree, and recursively construct the left and right
subtrees using the left and right halves of the array.
*/
class Solution {
  TreeNode *sortedArrayToBST(vector<int> &nums, int l, int r) {
    if (l > r) return NULL;

    int m = (l + r) / 2;
    TreeNode *rt = new TreeNode(nums[m]);
    rt->val = nums[m];
    rt->left = sortedArrayToBST(nums, l, m - 1);
    rt->right = sortedArrayToBST(nums, m + 1, r);

    return rt;
  }

 public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return sortedArrayToBST(nums, 0, sz(nums) - 1);
  }
};

int main() {
  vi v = {-10, -3, 0, 5, 9};
  var s = Solution();
  var t = s.sortedArrayToBST(v);
  return 0;
}
