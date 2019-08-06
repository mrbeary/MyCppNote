/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/


//这题的关键是如何处理random这个部分
class Solution {
public:
    Node* copyRandomList(Node* head) {
        int index = 0;
        Node* tmp = head;
        map<Node*,int> m; //用map来记录节点位于链表的第几个
        while (tmp)
        {
            m[tmp] = index;
            index++;
            tmp = tmp->next;  //先遍历一遍链表，记录每个节点的索引位置
        }
        vector<Node*> vt(index+1,NULL); //用vector来暂时存放所负责的链表节点
        index = 0;
        tmp = head;
        while (tmp)
        {
            vt[index] = new Node(tmp->val, NULL, NULL);
            index++;
            tmp = tmp->next;  //第二次遍历，建立复制的链表，这时我们还没处理 next 和 random 部分
        }
        while (head)
        {
            if (head->random == NULL) //random是否为NULL需要分开讨论一下，不然有可能将指向NULL的random指向第0个节点，
                vt[m[head]]->random = NULL; //因为NULL数值上等于0
            else
                vt[m[head]]->random = vt[m[head->random]];
            vt[m[head]]->next = vt[m[head]+1];
            head = head->next;
        } //第三次遍历，处理复制出来的节点的 next 和 random 部分，我们利用map可以知道random指向的是链表的第几个节点
        return vt[0]; //vt[0]就是复制的链表的头部，返回即可
    }
};