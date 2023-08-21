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

class Solution {
 public:
  vvi levelOrder(TreeNode *root) {
    vvi ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      vi a;
      int s = sz(q);
      while (s--) {
        var node = q.front();
        q.pop();

        if (!node) continue;

        a.pb(node->val);

        q.push(node->left);
        q.push(node->right);
      }
      if (!a.empty()) ans.pb(a);
    }
    return ans;
  }
};

int main() {
  var s = Solution();
  return 0;
}
