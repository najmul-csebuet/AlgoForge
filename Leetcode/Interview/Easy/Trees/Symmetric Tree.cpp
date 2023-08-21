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

class Solution_Iterative {
 public:
  bool isSymmetric(TreeNode *root) {
    stack<pair<TreeNode *, TreeNode *>> stk;
    stk.push({root->left, root->right});

    while (!stk.empty()) {
      var a = stk.top();
      stk.pop();

      var left = a.first;
      var right = a.second;

      if (left == NULL && right == NULL) {
        continue;
      }

      if (left == NULL || right == NULL || left->val != right->val) {
        return false;
      }

      stk.push({left->left, right->right});
      stk.push({left->right, right->left});
    }

    return true;
  }
};

class Solution_AC_Iterative_BFS {
 public:
  bool isSymmetric(TreeNode *root) {
    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty()) {
      int size = que.size();
      vi currLevel1, currLevel2;
      while (size > 0) {
        --size;

        var node = que.front();
        que.pop();

        int a = -101;
        if (node != NULL) {
          a = node->val;
          que.push(node->left);
          que.push(node->right);
        }

        currLevel1.push_back(a);
        currLevel2.push_back(a);
      }

      reverse(all(currLevel2));

      if (currLevel1 != currLevel2) {
        return false;
      }
    }

    return true;
  }
};

class Solution_AC_Recursive {
  bool check(TreeNode *left, TreeNode *right) {
    if (left == NULL && right == NULL) {
      return true;
    }

    if (left == NULL || right == NULL || left->val != right->val) {
      return false;
    }

    return check(left->left, right->right) && check(left->right, right->left);
  }

 public:
  bool isSymmetric(TreeNode *root) { return check(root->left, root->right); }
};

int main() {
  var s = Solution();
  return 0;
}
