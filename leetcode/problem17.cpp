

//利用递归
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        dic = {
            {},
            {},
            {'a','b','c'},
            {'d','e','f'},
            {'g','h','i'},
            {'j','k','l'},
            {'m','n','o'},
            {'p','q','r','s'},
            {'t','u','v'},
            {'w','x','y','z'}
        };//0 - 9 对应的按键映射
        res = {};
        
        string cur;
        func(digits, 0, cur);
        
        return res;
    }
private:
    vector<string> res;
    vector<vector<char> > dic;
    void func(string & digits, int index, string &cur) //主要功能在这实现
    {
        if (index == digits.size())
        {
            res.push_back(cur);
            return;
        }    
        int tmp = digits[index] - '0';
        for (int j = 0; j < dic[tmp].size(); j++)
        {
            cur += dic[tmp][j];  //选一个字符
            func(digits, index+1, cur); //选下一个字符
            cur.erase(cur.end()-1);
        }
        
    }
};
//存在问题：做了一些重复的工作
//待优化： 可以考虑实现带有“备忘录”的递归