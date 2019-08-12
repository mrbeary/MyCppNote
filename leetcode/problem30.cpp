

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.size() == 0 || words.size() == 0)
            return {};
        _s = s;
        res = {};
        for (int i = 0; i < words.size(); i++)
            mp[words[i]]++; //记录words里面的单词及出现次数
        wordLen = words[0].size(); //每个单词的长度
        
        
        int tmp = s.size() - (words.size() * wordLen);
        for (int i = 0; i <= tmp; i++)
        {
            func(i, i, words.size());
            
        }
        return res;
    }
private:
    vector<int> res, svt;
    int wordLen;
    map<string, int> mp; 
    string _s;
    void func(int& start, int index, int remain)  
    { //start为开始搜索的索引，index为当前索引，remain表示words里面还有多少个单词要挑
        --remain;
        string tmpword = _s.substr(index, wordLen);  //从index开始，长度为wordLen的子字符串
        
        if (mp.count(tmpword) == 0 || mp[tmpword] == 0) //如果在map里面没有这个子字符串或者对应的值为0，则返回
            return;
        
        if (remain == 0)
        {  //刚好符合
            res.push_back(start);
            return;
        }
        mp[tmpword]--; //拿走一个，然后往后面选
        func(start, index + wordLen, remain);
        ++mp[tmpword]; //放回去
    }
};