

//方案1，拿一个数组储存所有的节点，然后重排
/*

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head)
            return;
        vector<ListNode*> arr;
        while (head)
        {
            arr.push_back(head);
            head = head->next;
        }
        int l = 0, r = arr.size() - 1;
        while (l < r)
        {
            arr[l]->next = arr[r];
            arr[r]->next = arr[l+1];
            l++;
            r--;
        }
        arr[l]->next = NULL;
    
    }
};

 */
//方案2，先将链表分成两半，将第二段倒置，然后重排
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head)
            return;
        ListNode *p1, *p2;
        p1 = p2 = head;

        ListNode * trace = NULL;
        //下面这部分用于将链表分成两半
        while (p1 && p1->next)
        {
            trace = p2;
            p1 = p1->next->next;
            p2 = p2->next;
        }
        if (trace)
            trace->next = NULL;

        ListNode *head2 = p2;
        ListNode * pre = NULL;
        //下面这部分用于将第二段链表反转
        while (head2)
        {
            ListNode *tmp = head2->next;
            head2->next = pre;
            pre = head2;
            head2 = tmp;
        }
        head2 = pre;
        //下面将两条链表合并重排
        trace = NULL;
        while (head)
        {
            trace = head2;
            p1 = head->next;
            p2 = head2->next;
            head->next = head2;
            head2->next = p1;
            head = p1;
            head2 = p2;
        }
        trace->next = p2;
    }
};