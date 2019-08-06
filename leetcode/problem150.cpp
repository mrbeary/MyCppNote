/* 
主要思路：利用栈
逐个遍历给出的字符串数组 tokens
如果遇到数字，就直接推入栈
如果遇到运算符，就从栈顶取出两个元素，假设第一个取出x，第二个取出y，则运算结果 res=y 操作符 x
然后将res推入栈
继续遍历 tokens，直到走到最后
这时栈就只有 一个元素，这就是最后的结果
题目假设给出的式子都是可行的，因此我们不需要考虑式子不合法导致类似于栈为空的情况
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++)
        {
            string cur = tokens[i];
            if (isnumber(cur))
            {
                int tmp = transfer(cur);
                nums.push(tmp);
            }
            else
            {
                int x = nums.top();
                nums.pop();
                int y = nums.top();
                nums.pop();
                int tmp = 0;
                switch (cur[0]){
                    case '+':tmp = x + y; break;
                    case '-':tmp = y - x; break;
                    case '*':tmp = x * y; break;
                    case '/':tmp = y / x; break;
                }
                nums.push(tmp);
            }
        }
        return nums.top();
    }
private:
    bool isnumber(string & st)  //判断字符串st是否为数字，如果是就返回true，否则返回false
    {
        if (st.size() == 1)
        {
            switch (st[0]){
                case '+':
                case '-':
                case '*':
                case '/':   return false;
                default:    return true;
            }
        }
        return true;
    }
        
    int transfer(string & st) //在st是“数字”的前提下，将st的数值返回，注意：一定要确认st是“数字”才能调用此函数
    {
        int res = 0;
        if (st[0] == '-')
        {
            for (int i = 1; i < st.size(); i++)
            {
                res = res * 10 - (st[i]-'0');
            }
        }
        else
        {
            for (int i = 0; i < st.size(); i++)
                res = res * 10 + (st[i]-'0');
        }
        return res;
    }
};