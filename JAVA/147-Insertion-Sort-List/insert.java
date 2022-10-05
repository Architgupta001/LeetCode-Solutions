public class insert {
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        
        ListNode node = head;
        while(node != null){
            ListNode next = node.next;
            ListNode prev = dummy;
            while(prev.next != null && node.val > prev.next.val){
                prev = prev.next;
            }
            node.next = prev.next;
            prev.next = node;
            node = next;
        }
        return dummy.next;
    }
}
