class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == NULL)
            return NULL;
        ListNode *prev = NULL, *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
        return head;
    }
};