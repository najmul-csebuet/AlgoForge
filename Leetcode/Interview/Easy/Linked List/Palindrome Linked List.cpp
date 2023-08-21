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
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_AC_InPlace {
  var getMidNode(ListNode *head) {
    var slowPointer = head;
    var fastPointer = head;
    while (fastPointer->next != NULL && fastPointer->next->next != NULL) {
      slowPointer = slowPointer->next;
      fastPointer = fastPointer->next->next;
    }
    return slowPointer;
  }

  var reverseList(ListNode *head) {
    ListNode *previousNode = nullptr;
    ListNode *currentNode = head;

    while (currentNode != nullptr) {
      var nxt = currentNode->next;

      currentNode->next = previousNode;
      previousNode = currentNode;
      currentNode = nxt;
    }

    return previousNode;
  }

 public:
  bool isPalindrome(ListNode *head) {
    // 1 2 2 1
    // 1 2 3 2 1
    var midNode = getMidNode(head);
    var reversedHead = reverseList(midNode->next);

    // now check for palindrome
    var h1 = head;
    var h2 = reversedHead;
    var ok = true;

    while (ok && h2 != NULL) {
      if (h1->val != h2->val) {
        ok = false;
      }
      h1 = h1->next;
      h2 = h2->next;
    }

    // now reverse again to restore the list
    midNode->next = reverseList(reversedHead);

    return ok;
  }
};

class Solution_AC_Recursive {
  int getLen(ListNode *head) {
    int len = 0;
    while (head != nullptr) {
      ++len;
      head = head->next;
    }
    return len;
  }

  pair<bool, ListNode *> isPalin(ListNode *head, int maxDepth, int currentDepth,
                                 bool odd) {
    if (currentDepth == maxDepth) {
      if (odd) {
        // we are in middle single item
        return {true, head->next};
      } else {
        if (head->val == head->next->val) {
          return {true, head->next->next};
        }
        return {false, nullptr};
      }
    }

    var res = isPalin(head->next, maxDepth, currentDepth + 1, odd);
    if (!res.first) {
      return {false, nullptr};
    }
    if (head->val == res.second->val) {
      return {true, res.second->next};
    }
    return {false, nullptr};
  }

 public:
  bool isPalindrome(ListNode *head) {
    int n = getLen(head);
    if (n % 2) {
      var s = isPalin(head, (n + 1) / 2, 1, true);
      return s.first;
    }
    var s = isPalin(head, n / 2, 1, false);
    return s.first;
  }
};

int main() {
  ListNode a[4];
  a[0] = 1;
  a[1] = 1;
  a[2] = 2;
  a[3] = 1;
  rep(i, 0, 3) { a[i].next = &a[i + 1]; }
  a[3].next = nullptr;
  var s = Solution();
  var res = s.isPalindrome(&a[0]);
  return 0;
}
