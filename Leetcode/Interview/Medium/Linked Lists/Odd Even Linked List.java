
// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode oddEvenList(ListNode head) {

        ListNode odd = new ListNode(), even = new ListNode(), o = odd, e = even;
        int c = 1;
        while (head != null) {
            if (c % 2 == 1) {
                // odd node
                o.next = head;
                o = o.next;
            } else {
                // even node
                e.next = head;
                e = e.next;
            }
            head = head.next;
            ++c;
        }
        
        e.next = null;
        o.next = even.next;

        ListNode ans = odd.next;
        return ans;
    }
}

class Tester {
    public static void main(String[] args) {
        Solution s = new Solution();
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        var ans = s.oddEvenList(head);
        System.out.println(ans);
    }
}