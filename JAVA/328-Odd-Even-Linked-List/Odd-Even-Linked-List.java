/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode odd = new ListNode(-1);
        ListNode even = new ListNode(-1);
        ListNode op = odd, ep = even, curr = head;
        int idx = 1;
        while(curr != null){
            if((idx & 1) == 1){
                op.next = curr;
                op = curr;
            }else{
                ep.next = curr;
                ep = curr;
            }
            curr = curr.next;
            idx++;
        }
        ep.next = null;
        op.next = even.next;
        even.next = null;
        ListNode nHead = odd.next;
        odd.next = null;
        return nHead;
    }
}