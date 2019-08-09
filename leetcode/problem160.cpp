
/*
用两个数组记录所有节点
然后从两个数组的最后开始往前找
空间复杂度为 O(m + n)
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode *> vt1, vt2;
        while (headA)
        {
            vt1.push_back(headA);
            headA = headA->next;
        }
        while (headB)
        {
            vt2.push_back(headB);
            headB = headB->next;
        }
        int yes = 0;
        int i = vt1.size() - 1, j = vt2.size() - 1;
        for (; i >= 0 && j >= 0 && vt1[i] == vt2[j]; i--, j--) yes++; //如果这个循环进行了至少一次，则yes大于0
        if (yes == 0) //若yes为0说明无公共节点
            return NULL;
        return vt1[i + 1];
    }
};

//O(1) 空间复杂度版本
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = 0, lenb = 0;
        ListNode *tmpA = headA, *tmpB = headB;
        while (tmpA)
        {
            lena++;
            tmpA = tmpA->next;
        }
        while (tmpB)
        {
            lenb++;
            tmpB = tmpB->next;
        }
        int decrese = abs(lena - lenb);
        if (lena > lenb)
        {
            for (int i = 0; i < decrese; i++)
                headA = headA->next;
        }
        else
        {
            for (int i = 0; i < decrese; i++)
                headB = headB->next;
        }
        while (headA && headB && headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};