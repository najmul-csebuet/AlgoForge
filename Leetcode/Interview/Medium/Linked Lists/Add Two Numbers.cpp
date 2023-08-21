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

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// AC
// Compact
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    int sum = 0;
    ListNode *ans = new ListNode(), *temp = ans;
    while (l1 || l2 || carry) {
      sum = carry;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      temp->next = new ListNode(sum % 10);
      temp = temp->next;
      carry = sum / 10;
    }
    return ans->next;
  }
};

class Solution_AC {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ans = 0;
    ListNode *c1 = l1, *c2 = l2, *a = ans;
    int carry = 0;
    while (c1 && c2) {
      int s = c1->val + c2->val + carry;
      ListNode* c = new ListNode(s % 10);
      carry = s / 10;
      if (a) {
        a->next = c;
      } else {
        ans = c;
      }
      a = c;
      c1 = c1->next;
      c2 = c2->next;
    }

    while (c1) {
      int s = c1->val + carry;
      ListNode* c = new ListNode(s % 10);
      carry = s / 10;
      if (a) {
        a->next = c;
      }
      a = c;
      c1 = c1->next;
    }

    while (c2) {
      int s = c2->val + carry;
      ListNode* c = new ListNode(s % 10);
      carry = s / 10;
      if (a) {
        a->next = c;
      }
      a = c;
      c2 = c2->next;
    }

    if (carry) {
      ListNode* c = new ListNode(carry);
      a->next = c;
    }

    return ans;
  }
};

int main() {
  var s = Solution();
  ListNode* a = new ListNode(2);
  a->next = new ListNode(4);
  a->next->next = new ListNode(3);

  ListNode* b = new ListNode(5);
  b->next = new ListNode(6);
  b->next->next = new ListNode(4);

  var ans = s.addTwoNumbers(a, b);

  return 0;
}
