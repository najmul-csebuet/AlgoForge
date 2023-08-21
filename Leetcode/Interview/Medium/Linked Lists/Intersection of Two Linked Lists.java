// Definition for singly-linked list.

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

class Solution_AC_BOSS {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA, b = headB;
        while (a != b) {
            a = (a != null) ? a.next : headB;
            b = (b != null) ? b.next : headA;
        }
        return a;
    }
}

class Solution_AC_Cycle_Math {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        // find tail of list A
        ListNode tail = headA;
        while (tail.next != null) {
            tail = tail.next;
        }
        // then connect tail of A with head of A
        tail.next = headA;
        // so this is a cycle

        // now if B meets this cycle, we can use floyds algo
        // if they does not meet, one of them reach null
        ListNode slow = headB, fast = headB;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow != fast) {
                continue;
            }

            // they meet!
            // fast pointer travels 2 times faster then slow pointer
            // so slow traversed total X distance and fast traversed 2X distance.
            // so headB to meeting place is X as slow went that distance
            // and meeting place to meeting place along the cycle is X as fast pointer went
            // that distance extra
            // We can write X = a + b
            // where a = distance from headB to cycle start and
            // b = cycle start to meeting place
            // b is common for both path: headB to meeting and meeting to meeting along the
            // cycle
            // so meeting place to cycle start is a distance away
            // so is headB to cycle start
            // so we can travel from headB and from meeting place to meeting place along
            // cycle
            // they will meet as distance is same
            // this time they both travel at same speed
            // we will find the cycle start when they meet
            ListNode secondSlow = headB;
            while (slow != secondSlow) {
                slow = slow.next;
                secondSlow = secondSlow.next;
            }

            // they meet so slow is the desired node
            // before you return it disconnect the tail of A to head of A
            tail.next = null;
            return slow;
        }

        // fast is null, so they do not meet
        // before you return, disconnect the tail of A to head of A
        tail.next = null;
        return null;
    }
}

class Solution_AC_Len_Adjust {
    private int getLen(ListNode head) {
        int len = 0;
        while (head != null) {
            ++len;
            head = head.next;
        }
        return len;
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lenA = getLen(headA);
        int lenB = getLen(headB);

        if (lenA > lenB) {
            // traverse A so that both become equal len list
            while (lenA > lenB) {
                headA = headA.next;
                --lenA;
            }
        } else {
            // traverse A so that both become equal len list
            while (lenB > lenA) {
                headB = headB.next;
                --lenB;
            }
        }

        // now both are equal len list
        // they should meet at some non null node
        // if any of them is null then no intersection
        while (headA != null && headB != null) {
            if (headA == headB) {
                return headA;
            }
            headA = headA.next;
            headB = headB.next;
        }
        return null;
    }
}

class Solution_AC_Normal {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        ListNode t = headA, ans = null;
        while (t != null) {
            t.val = -t.val;
            t = t.next;
        }
        t = headB;
        boolean flag = false;
        while (t != null) {
            if (t.val < 0) {
                ans = t;
                flag = true;
                break;
            }
            t = t.next;
        }

        // restore list
        t = headA;
        while (t != null) {
            t.val = -t.val;
            t = t.next;
        }

        return ans;
    }
}

class Tester {
    public static void main(String[] args) {
        Solution s = new Solution();
    }
}