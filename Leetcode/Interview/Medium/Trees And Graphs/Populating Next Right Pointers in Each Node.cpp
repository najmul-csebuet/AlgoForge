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

// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// BFS with constant space
// utilizing next pointer
class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return root;

    for (auto r = root; r->left; r = r->left) {
      for (auto curr = r; curr; curr = curr->next) {
        // define curr next
        curr->left->next = curr->right;
        curr->right->next = curr->next ? curr->next->left : 0;
      }
    }
    return root;
  }
};

// DFS
// utilizing next pointer
class Solution_AC {
 public:
  Node* connect(Node* root) {
    if (!root || !root->left) {
      return root;
    }

    root->left->next = root->right;
    root->right->next = root->next ? root->next->left : 0;

    connect(root->left);
    connect(root->right);

    return root;
  }
};

// Plain BFS: Right to Left traversal
class Solution_BFS_RTL {
 public:
  Node* connect(Node* root) {
    queue<Node*> q;

    if (root) q.push(root);

    while (!q.empty()) {
      Node* lastRightNode = nullptr;
      int currLevelCount = q.size();

      while (currLevelCount-- > 0) {
        auto curr = q.front();
        q.pop();

        curr->next = lastRightNode;
        lastRightNode = curr;

        if (curr->right != nullptr) {
          q.push(curr->right);
          q.push(curr->left);
        }
      }
    }
    return root;
  }
};

class Solution_AC_Good_Idea {
 public:
  Node* connect(Node* root) {
    if (!root || !root->left) return root;

    Node* l = root->left;
    Node* r = root->right;

    while (l) {
      l->next = r;
      l = l->right;
      r = r->left;
    }

    connect(root->left);
    connect(root->right);

    return root;
  }
};

class Solution_WA {
  Node* lastRightNode;
  int depthOfLastRightNode;

  Node* connect(Node* root, int depth) {
    if (root == nullptr || root->left == nullptr) {
      return root;
    }

    // try to wind
    if (depth + 1 == depthOfLastRightNode) {
      lastRightNode->next = root->left;
    }
    root->left->next = root->right;
    lastRightNode = root->right;
    depthOfLastRightNode = depth + 1;

    connect(root->left, 1);
    connect(root->right, 1);

    return root;
  }

 public:
  Node* connect(Node* root) {
    lastRightNode = nullptr;
    depthOfLastRightNode = -1;
    return connect(root, 0);
  }
};

void testCase1() {
  var s = Solution();
  Node* nodes[8];
  rep(i, 1, 8) { nodes[i] = new Node(i); }

  rep(i, 1, 4) {
    nodes[i]->left = nodes[2 * i];
    nodes[i]->right = nodes[2 * i + 1];
  }
  Node* ans = s.connect(nodes[1]);
  cout << (ans->left->next == ans->right) << endl;
  cout << (ans->left->left->next == ans->left->right) << endl;
  cout << (ans->left->right->next == ans->right->left) << endl;
  cout << (ans->right->left->next == ans->right->right) << endl;
}

void testCase2() {
  var s = Solution();
  Node* nodes[16];
  rep(i, 1, 16) { nodes[i] = new Node(i); }

  rep(i, 1, 8) {
    nodes[i]->left = nodes[2 * i];
    nodes[i]->right = nodes[2 * i + 1];
  }
  Node* ans = s.connect(nodes[1]);
  cout << (ans->left->next == ans->right) << endl;
  cout << (ans->left->left->next == ans->left->right) << endl;
  cout << (ans->left->right->next == ans->right->left) << endl;
  cout << (ans->right->left->next == ans->right->right) << endl;
}

int main() {
  testCase2();
  return 0;
}
