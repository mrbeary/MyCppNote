
/*
栈的部分使用了 stack<int>
因为要返回最小值，所以我想到了用 最小堆
虽然通过了所有测试用例，但leetcode上显示运行时间巨长，1000+ms
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        heap = {};
    }
    
    void push(int x) {
        st.push(x);
        heap.push_back(x);
        make_heap(heap.begin(), heap.end(), func);
    }
    
    void pop() {
        int tmp = st.top();
        st.pop();
        vector<int>::iterator ite;
        for (ite = heap.begin(); *ite != tmp; ite++);
        heap.erase(ite);
        make_heap(heap.begin(), heap.end(), func);  //每次出栈和入栈都要更新一下堆
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return heap[0];
    }
private:
    stack<int> st;
    vector<int> heap;
    static bool func(int n1, int n2)
    {
        return ! (n1 < n2);
    }
};

/*
方案2：参考了讨论区的思路
使用两个栈
一个是储存所有数据的栈，另一个是储存最小值的栈
如果一个新值入栈，这个值比最小值的栈顶元素小，那么这个值也要推入最小值元素的栈，相当与更新最小值
 */

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        st1.push(x);
        if (st2.empty() || st2.top() >= x)
            st2.push(x);  //若条件符合，就更新最小值
    }
    
    void pop() {
        if (st1.top() == st2.top())
            st2.pop();
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
private:
    stack<int> st1; //储存所有值
    stack<int> st2; //储存最小值
};
