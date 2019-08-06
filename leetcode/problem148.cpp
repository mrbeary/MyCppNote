
//链表版的快速排序
//参考了 STL里链表快速排序的思路
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<ListNode*> buffer(64,NULL); //缓冲区
        int fill = 0;
        while (head)
        {
            ListNode *newone = head;
            head = head->next;
            newone->next = NULL;
            int i = 0;
            while (buffer[i])
            {
                newone = mergeList(&newone, &buffer[i]);
                i++;
            }
            if (i == fill)
                fill++;
            swap(newone, buffer[i]);
        }
        ListNode *res = NULL;
        for (int i = 0; i < fill; i++)
        {
            res = mergeList(&buffer[i], &res);
        }
        return res;
    }
    
private:
    ListNode *mergeList(ListNode **a, ListNode **b)
    {
        ListNode *head;
        if (*a == NULL)
        {
            head = *b;
            *b = NULL;
            return head;
        }
        else if (*b == NULL)
        {
            head = *a;
            *a = NULL;
            return head;
        }
        head = new ListNode(0);
        ListNode *tmp = head;
        while (*a && *b)
        {
            if ((*a)->val < (*b)->val)
            {
                tmp->next = *a;
                *a = (*a)->next;
                tmp->next->next = NULL;
            }
            else
            {
                tmp->next = *b;
                *b = (*b)->next;
                tmp->next->next = NULL;
            }
            tmp = tmp->next;
        }
        if (*a)
        {
            tmp->next = *a;
            *a = NULL;
        }
        else
        {
            tmp->next = *b;
            *b = NULL;
        }
        tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
};