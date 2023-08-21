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
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (nullptr == head) return false;
    var slow = head;
    var fast = head;
    while (nullptr != fast->next && nullptr != fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};

class Solution_AC_MagicValue_Setting {
 public:
  bool hasCycle(ListNode *head) {
    var h = head;
    var magicVal = 1e5 + 1;
    while (h != nullptr) {
      if (h->val == magicVal) {
        // we found a cycle
        return true;
      }
      h->val = magicVal;
      h = h->next;
    }
    return false;
  }
};

int main() {
  var s = Solution();
  return 0;
}
