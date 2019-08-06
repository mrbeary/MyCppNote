
//链表的插入排序
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newhead = new ListNode(INT_MIN);
        while (head)
        {
            ListNode *tmp = newhead;
            while (tmp->next != NULL && tmp->next->val < head->val)
            {
                tmp = tmp->next;
            }
            ListNode *tmphead = head->next;
            head->next = tmp->next;
            tmp->next = head;
            head = tmphead;
        }
        return newhead->next;
    }
};