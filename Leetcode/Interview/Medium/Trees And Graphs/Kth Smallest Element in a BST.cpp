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

class Solution {
  TreeNode *kth(TreeNode *root, int &a) {
    if (!root) {
      return nullptr;
    }

    auto ans = kth(root->left, a);
    if (ans) return ans;

    a--;
    if (!a) {
      return root;
    }

    ans = kth(root->right, a);
    return ans;
  }

 public:
  int kthSmallest(TreeNode *root, int k) {
    return kth(root, k)->val;
  }
};

// AC
class Solution {
  TreeNode *kthSmallest(TreeNode *root, int &a, int k) {
    if (!root) {
      return nullptr;
    }

    auto ans = kthSmallest(root->left, a, k);
    if (ans) return ans;

    a++;
    if (a == k) {
      return root;
    }

    ans = kthSmallest(root->right, a, k);
    return ans;
  }

 public:
  int kthSmallest(TreeNode *root, int k) {
    int a = 0;
    return kthSmallest(root, a, k)->val;
  }
};

void testCase1() {
  // var s = Solution();
}

int main() {
  testCase1();
  return 0;
}
