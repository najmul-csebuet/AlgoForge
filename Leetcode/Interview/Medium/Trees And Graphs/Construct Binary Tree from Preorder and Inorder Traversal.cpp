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

// AC Reference variable
class Solution {
  TreeNode *buildTree(int &rootIndex, vi &preorder, vi &inorder) {
    if (sz(inorder) == 0) return nullptr;

    int root = preorder[rootIndex];
    TreeNode *rootNode = new TreeNode(root);

    if (1 == sz(inorder)) {
      return rootNode;  // last node
    }

    int indexInIn = find(all(inorder), root) - inorder.begin();
    vi inLeft = {inorder.begin(), inorder.begin() + indexInIn};
    vi inRight = {inorder.begin() + indexInIn + 1, inorder.end()};

    if (sz(inLeft) > 0) {
      rootIndex++;
    }
    rootNode->left = buildTree(rootIndex, preorder, inLeft);

    if (sz(inRight) > 0) {
      rootIndex++;
    }
    rootNode->right = buildTree(rootIndex, preorder, inRight);

    return rootNode;
  }

 public:
  TreeNode *buildTree(vi &preorder, vi &inorder) {
    int index = 0;
    var ans = buildTree(index, preorder, inorder);
    return ans;
  }
};

class Solution_AC_Pointer {
  TreeNode *buildTree(int *rootIndexPtr, vi &preorder, vi &inorder) {
    if (sz(inorder) == 0) return nullptr;

    int rootIndex = *rootIndexPtr;

    int root = preorder[rootIndex];
    TreeNode *rootNode = new TreeNode(root);

    if (1 == sz(inorder)) {
      return rootNode;  // last node
    }

    int indexInIn = find(all(inorder), root) - inorder.begin();
    vi inLeft = {inorder.begin(), inorder.begin() + indexInIn};
    vi inRight = {inorder.begin() + indexInIn + 1, inorder.end()};

    if (sz(inLeft) > 0) {
      (*rootIndexPtr)++;
    }
    rootNode->left = buildTree(rootIndexPtr, preorder, inLeft);

    if (sz(inRight) > 0) {
      (*rootIndexPtr)++;
    }
    rootNode->right = buildTree(rootIndexPtr, preorder, inRight);

    return rootNode;
  }

 public:
  TreeNode *buildTree(vi &preorder, vi &inorder) {
    int index = 0;
    var ans = buildTree(&index, preorder, inorder);
    return ans;
  }
};

class Solution_AC_Good {
 public:
  TreeNode *buildTree(vi &preorder, vi &inorder) {
    if (sz(preorder) == 0) return nullptr;

    // first node in preorder traversal is root
    int r = preorder[0];
    TreeNode *root = new TreeNode(r);

    if (sz(preorder) == 1) {
      return root;
    }

    int index = find(all(inorder), r) - inorder.begin();
    vi inorderLeft = {inorder.begin(), inorder.begin() + index};
    vi inorderRight = {inorder.begin() + index + 1, inorder.end()};

    vi preorderLeft = {preorder.begin() + 1,
                       preorder.begin() + 1 + sz(inorderLeft)};
    vi preorderRight = {preorder.end() - sz(inorderRight), preorder.end()};

    root->left = buildTree(preorderLeft, inorderLeft);
    root->right = buildTree(preorderRight, inorderRight);

    return root;
  }
};

class Solution_AC {
 public:
  TreeNode *buildTree(vi &preorder, vi &inorder) {
    if (sz(preorder) == 0) return nullptr;

    // first node in preorder traversal is root
    int r = preorder[0];
    TreeNode *root = new TreeNode(r);

    if (sz(preorder) == 1) {
      return root;
    }

    vi inorderLeft, inorderRight;

    int i = 0;
    for (; i < sz(inorder); ++i) {
      if (inorder[i] != r) {
        inorderLeft.pb(inorder[i]);
      } else {
        break;
      }
    }

    unordered_map<int, bool> mp;
    for (i = i + 1; i < sz(inorder); ++i) {
      inorderRight.pb(inorder[i]);
      mp[inorder[i]] = true;
    }

    vi preorderLeft, preorderRight;

    for (i = 1; i < sz(preorder); ++i) {
      if (!mp[preorder[i]]) {
        preorderLeft.pb(preorder[i]);
      } else {
        break;
      }
    }

    for (; i < sz(preorder); ++i) {
      preorderRight.pb(preorder[i]);
    }

    root->left = buildTree(preorderLeft, inorderLeft);
    root->right = buildTree(preorderRight, inorderRight);

    return root;
  }
};

void testCase1() {
  vi pre = {3, 9, 20, 15, 7}, in = {9, 3, 15, 20, 7};
  var s = Solution();
  var r = s.buildTree(pre, in);
  cout << (r->val == 3) << endl;
}

void testCase2() {
  vi pre = {1, 2}, in = {2, 1};
  var s = Solution();
  var r = s.buildTree(pre, in);
  cout << (r->val == 1) << endl;
}

void testCase3() {
  vi pre = {1, 2}, in = {1, 2};
  var s = Solution();
  var r = s.buildTree(pre, in);
  cout << (r->val == 1) << endl;
}

int main() {
  testCase1();
  testCase2();
  testCase3();
  return 0;
}
