class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:

        root = front = ListNode(None)
        front.next = head
        while head and head.next:
            temp = head.next
            head.next = temp.next
            temp.next = head

            front.next = temp
            head = head.next
            front = front.next.next

        return root.next

if __name__=="__main__":
    solution = Solution()
    head = ListNode(1,ListNode(2, ListNode(3, ListNode(4, None))))
    ret = solution.swapPairs(head)
    now = ret
    while now is not None:
        print(now.val, end = " ")
        now = now.next
