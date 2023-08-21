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

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};

class Solution_AC_NotSoGood {
 public:
  void deleteNode(ListNode* node) {
    ListNode *prev = nullptr, *curr = node;
    while (curr->next != nullptr) {
      curr->val = curr->next->val;
      prev = curr;
      curr = curr->next;
    }

    prev->next = nullptr;
    free(curr);
  }
};

int main() {
  var s = Solution();
  return 0;
}
