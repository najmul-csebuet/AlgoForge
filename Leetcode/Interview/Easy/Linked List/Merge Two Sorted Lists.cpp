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

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
    // if any one is empty, return other list
    if (nullptr == list1) return list2;
    if (nullptr == list2) return list1;

    // lets make sure list1 has smaller val always
    if (list1->val > list2->val) swap(list1, list2);
    ListNode *head = list1;

    // see how far we can travel along list1
    // after that swap list1, list2
    // travel list1 again
    while (nullptr != list1 && nullptr != list2)
    {
        ListNode *temp;
        while(nullptr != list1 && (list1->val <= list2->val)) {
            temp = list1;
            list1 = list1->next;
        }
        temp->next = list2;
        swap(list1, list2);
    }
    
    return head;
  }
};

class Solution_AC {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *head, *tail;

    if (nullptr == list1) {
      return list2;
    }

    if (nullptr == list2) {
      return list1;
    }

    if (list1->val <= list2->val) {
      head = tail = list1;
      list1 = list1->next;
    } else {
      head = tail = list2;
      list2 = list2->next;
    }

    while (nullptr != list1 && nullptr != list2) {
      if (list1->val <= list2->val) {
        tail->next = list1;
        tail = list1;
        list1 = list1->next;
      } else {
        tail->next = list2;
        tail = list2;
        list2 = list2->next;
      }
    }

    while (nullptr != list1) {
      tail->next = list1;
      tail = list1;
      list1 = list1->next;
    }

    while (nullptr != list2) {
      tail->next = list2;
      tail = list2;
      list2 = list2->next;
    }

    tail->next = nullptr;
    return head;
  }
};

int main() {
  ListNode a[3], b[3];
  vi av = {1, 2, 4};
  vi bv = {1, 3, 4};

  rep(i, 0, 3) {
    a[i].val = av[i];
    if (i + 1 < 3) {
      a[i].next = &a[i + 1];
    } else {
      a[i].next = nullptr;
    }
  }

  rep(i, 0, 3) {
    b[i].val = bv[i];
    if (i + 1 < 3) {
      b[i].next = &b[i + 1];
    } else {
      b[i].next = nullptr;
    }
  }

  var s = Solution();
  var res = s.mergeTwoLists(&a[0], &b[0]);
  return 0;
}
