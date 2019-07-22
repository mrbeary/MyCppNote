
/*
    首先判断链表有没有环：
    定义两个指针 fast 和 slow，fast每次走两步，slow每次走一步，如果fast走到尾了，就说明没有环，返回 NULL
    如果fast和slow 相遇了，就说明有环，循环在此停下；
    fast回到链表头部，fast = head；
    这次fast 和 slow 每次走一步
    当他们相遇时，就是环的入口
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast = head, *slow = head;
        while (fast)
        {
            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
            }
            else
                return NULL;
            slow = slow->next;
            if (slow == fast)
                break;
        }
        if (!fast)
            return NULL;
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};