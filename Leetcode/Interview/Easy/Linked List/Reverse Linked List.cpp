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
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution_AC_Recursive {
  pair<ListNode*, ListNode*> reverse(ListNode* head) {
    if (nullptr == head->next) {
      return {head, head};
    }
    var res = reverse(head->next);
    head->next = nullptr;
    res.first->next = head;
    return {head, res.second};
  }

 public:
  ListNode* reverseList(ListNode* head) {
    if (nullptr == head) {
      return head;
    }
    var res = reverse(head);
    return res.second;
  }
};

class Solution_AC_Iterative {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
      return head;
    }
    // 1 -> 2 -> 3 -> 4
    var curr = head;
    var next = head->next;
    head->next = nullptr;
    while (next != nullptr) {
      var newNext = next->next;
      next->next = curr;
      curr = next;
      next = newNext;
    }
    return curr;
  }
};

int main() {
  var s = Solution();
  ListNode a[5];
  rep(i, 0, 4) { a[i].next = &a[i + 1]; }
  a[4].next = nullptr;
  rep(i, 0, 5) { a[i].val = i + 1; }
  s.reverseList(&a[0]);
  return 0;
}
