
// 定义两个指针fast 和 slow， fast每次走两步， slow每次走一步，如果有环，则会相遇
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * fast = head, * slow = head;
        while (fast)
        {
            if (fast->next)
            {
                fast = fast->next->next;
            }
            else
                return false;
            slow = slow->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};