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

class Solution_AC_Iterative {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // find len
    int len = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
      ++len;
      temp = temp->next;
    }

    int targetFromStart = len - n + 1;
    int c = 1;
    ListNode *prev = nullptr, *curr = head;
    while (c < targetFromStart) {
      prev = curr;
      curr = curr->next;
      ++c;
    }

    // found the node in curr
    if (prev == nullptr) {
      prev = curr;
      curr = curr->next;
      // delete prev;
      head = curr;
    } else {
      temp = curr;
      prev->next = curr->next;
      delete temp;
    }

    return head;
  }
};

class Solution_AC_Recursive {
 private:
  int index(ListNode** prev, ListNode** curr, int nn) {
    if (curr == nullptr) return 0;

    int n;

    if ((*curr)->next != nullptr)
      n = index(curr, &((*curr)->next), nn) + 1;
    else {
      n = index(curr, nullptr, nn) + 1;
    }

    if (n == nn) {
      if (prev != nullptr)
        (*prev)->next = (*curr)->next;
      else {
        *curr = (*curr)->next;
      }
    }

    return n;
  }

 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode** prev = nullptr;
    index(prev, &head, n);
    return head;
  }
};

int main() {
  // var s = Solution();
  return 0;
}
