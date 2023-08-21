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

// inorder iterative
class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    
    stack<TreeNode *> stk;

    var curr = root;
    TreeNode *prev = nullptr;

    while (!stk.empty() || curr != nullptr) {
      
      while(curr != nullptr) {
        stk.push(curr);
        curr = curr->left;
      }

      var node = stk.top();
      stk.pop();

      if(prev != nullptr && prev->val >= node->val) {
        return false;
      }

      prev = node;
      curr = node->right;
    }

    return true;
  }
};

class Solution_Inorder_Traversal_Idea {
  TreeNode *prev = nullptr;

 public:
  bool isValidBST(TreeNode *root) {
    if (nullptr == root) {
      return true;
    }

    if (!isValidBST(root->left)) {
      return false;
    }

    if (nullptr != prev && prev->val >= root->val) {
      return false;
    }

    prev = root;
    return isValidBST(root->right);
  }
};

class Solution_AC_WithNodes {
  bool isValid(TreeNode *root, TreeNode *minNode = nullptr,
               TreeNode *maxNode = nullptr) {
    if (nullptr == root) return true;
    if (minNode && minNode->val >= root->val) return false;
    if (maxNode && maxNode->val <= root->val) return false;
    return isValid(root->left, minNode, root) &&
           isValid(root->right, root, maxNode);
  }

 public:
  bool isValidBST(TreeNode *root) { return isValid(root); }
};

class Solution_AC_WithValues {
  bool isValidBST(TreeNode *root, long minRange, long maxRange) {
    if (root == nullptr) {
      return true;
    }

    long rv = root->val;
    if (minRange >= rv || rv >= maxRange) {
      return false;
    }
    return isValidBST(root->left, minRange, rv) &&
           isValidBST(root->right, rv, maxRange);
  }

 public:
  bool isValidBST(TreeNode *root) {
    // stack<tuple<TreeNode *, long, long>> stk;
    return isValidBST(root, LONG_MIN, LONG_MAX);
  }
};

class Solution_AC_BAD {
  int minValue(TreeNode *root) {
    if (nullptr == root) {
      return INT_MAX;
    }
    return min(root->val, min(minValue(root->left), minValue(root->right)));
  }

  int maxValue(TreeNode *root) {
    if (nullptr == root) {
      return INT_MIN;
    }
    return max(root->val, (maxValue(root->left), maxValue(root->right)));
  }

 public:
  bool isValidBST(TreeNode *root) {
    if (nullptr == root) {
      return true;
    }

    if (root->left != nullptr) {
      int l = maxValue(root->left);
      if (l >= root->val) {
        return false;
      }
    }

    if (root->right != nullptr) {
      int r = minValue(root->right);
      if (r <= root->val) {
        return false;
      }
    }

    bool lv = isValidBST(root->left);
    bool rv = isValidBST(root->right);

    return lv && rv;
  }
};

int main() {
  TreeNode a2, a1, a3;
  a2.val = 2;
  a1.val = 1;
  a3.val = 3;
  a2.left = &a1;
  a2.right = &a3;
  /* TreeNode a5, a1, a4, a3, a6;
  a5.val = 5;
  a1.val = 1;
  a4.val = 4;
  a3.val = 3;
  a6.val = 6;

  a5.left = &a1;
  a5.right = &a4;

  a4.left = &a3;
  a4.right = &a6; */

  var s = Solution();
  bool a = s.isValidBST(&a2);
  cout << a << endl;
  return 0;
}
