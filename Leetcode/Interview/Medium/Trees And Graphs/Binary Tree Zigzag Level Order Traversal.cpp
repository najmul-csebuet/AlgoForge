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
 public:
  vvi zigzagLevelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    vvi ans;
    bool flip = false;

    while (!q.empty()) {
      int n = sz(q);
      vi currentLevel;
      while (n--) {
        var node = q.front();
        q.pop();
        if (node == nullptr) continue;
        currentLevel.pb(node->val);
        q.push(node->left);
        q.push(node->right);
      }
      if (flip) {
        reverse(all(currentLevel));
      }
      flip = !flip;
      if (!currentLevel.empty()) ans.pb(currentLevel);
    }
    return ans;
  }
};

class Solution_Wrong {
 public:
  vvi zigzagLevelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    q.emplace(root);
    bool leftToRight = true;
    vvi ans;

    while (!q.empty()) {
      int currentLevelSize = sz(q);
      vi currentLevel;

      while (currentLevelSize--) {
        var node = q.front();
        q.pop();
        if (node == nullptr) continue;

        currentLevel.pb(node->val);

        if (leftToRight) {
          q.emplace(node->right);
          q.emplace(node->left);

        } else {
          q.emplace(node->left);
          q.emplace(node->right);
        }
      }

      leftToRight = !leftToRight;

      if (!currentLevel.empty()) ans.pb(currentLevel);
    }

    return ans;
  }
};

int main() {
  var s = Solution();
  return 0;
}
