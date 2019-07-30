
//用类似双指针的方法
/* 1.0版本
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> salpha(127,0); // 记录子字符串中有的字母和数量
        map<int,int> tmap; //记录t拥有的字母和数量
        for (int i = 0; i < t.size(); i++)
        {
            char ct = t[i];
            ++tmap[ct-'\0'];
        }
        int left = 0, right = -1;
        string res = "";
        while (left != s.size())
        {
            if (isvalid(salpha, tmap))
            {
                string tmp(s.begin()+left,s.begin()+right+1);
                if (res == "")
                    res = tmp;
                else
                    res = (res.size() > tmp.size())? tmp : res;
                salpha[s[left]-'\0']--;
                left++;//左边的指针向右移，尝试缩小子字符串的长度
            }
            else
            {
                right++;
                if (right == s.size())
                    break;
                salpha[s[right]-'\0']++;//右边的指针右移，尝试使得子字符串满足条件
            }
        }
        return res;
    }
    
private:
    bool isvalid(vector<int>& salpha, map<int,int> & tmap)
    {//这个函数用来判断子字符串是否符合要求
        map<int,int>::iterator ite;
        for (ite = tmap.begin(); ite != tmap.end(); ite++)
        {
            if (ite->second > salpha[ite->first])
                break;
        }
        return ite == tmap.end();
    }
};
*/

//2.0版本，改进了判断子字符串是否符合要求的方法
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> salpha(127,0);
        map<int,int> tmap;
        for (int i = 0; i < t.size(); i++)
        {
            char ct = t[i];
            ++tmap[ct-'\0'];
        }
        int left = 0, right = 0, count = t.size(); //count用来判断子字符串是否符合要求
        string res = "";
        while (right != s.size())
        {
            char ct = s[right]; //右边的指针右移，试图使子字符串满足条件
            if (tmap[ct-'\0'] > 0) //如果对应的字母数量大于0，则说明此位置的字母在t里面
                count--;
            tmap[ct-'\0']--; // 匹配了一个，相应的记录减1
            right++;
            while (count == 0) //当子字符串满足条件时执行
            {
                string tmp(s.begin()+left,s.begin()+right);
                if (res == "")
                    res = tmp;
                else
                    res = (res.size() > tmp.size())? tmp : res; //更新结果字符串 res
                tmap[s[left]-'\0']++; //将此位置的字符拿走，相应记录+1
                if (tmap[s[left]-'\0'] > 0) //如果对应位置的字母数量>0，说明子字符串不满足条件了
                    count++;
                left++; //左边的指针向右移，尝试缩小窗口的大小
            }
        }
        return res;
    }
};

//3.0版本
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> salpha(127,0);
        map<int,int> tmap;
        for (int i = 0; i < t.size(); i++)
        {
            char ct = t[i];
            ++tmap[ct-'\0'];
        }
        int left = 0, right = 0, count = t.size();
        int head = 0, rear = INT_MAX;
        string res = "";
        while (right != s.size())
        {
            char ct = s[right];
            if (tmap[ct-'\0'] > 0)
                count--;
            tmap[ct-'\0']--;
            right++;
            while (count == 0)
            {
                if (right - left < rear - head)
                {
                    head = left;
                    rear = right; //在更新结果字符串这部分作了点改动，只记录最优解的头尾位置
                    //1.0 和 2.0 版本可能因为创建字符串太多，所以leetcode上显示的内存使用有200+MB，大得有点夸张
                    //现在这个版本显示的内存使用为10+MB
                }
                tmap[s[left]-'\0']++;
                if (tmap[s[left]-'\0'] > 0)
                    count++;
                left++;
            }
        }
        res = (rear == INT_MAX)? "" : string(s.begin()+head, s.begin()+rear);
        return res;
    }
};

//3.1版本
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> salpha(127,0);
        //map<int,int> tmap;
        vector<int> tmap(127,0); //这里由改成用vector，查找时间变成线性，leetcode上显示的用时比3.0版本要短
        for (int i = 0; i < t.size(); i++)
        {
            char ct = t[i];
            ++tmap[ct-'\0'];
        }
        int left = 0, right = 0, count = t.size();
        int head = 0, rear = INT_MAX;
        string res = "";
        while (right != s.size())
        {
            char ct = s[right];
            if (tmap[ct-'\0'] > 0)
                count--;
            tmap[ct-'\0']--;
            right++;
            while (count == 0)
            {
                if (right - left < rear - head)
                {
                    head = left;
                    rear = right; //在更新结果字符串这部分作了点改动，只记录最优解的头尾位置
                    //1.0 和 2.0 版本可能因为创建字符串太多，所以leetcode上显示的内存使用有200+MB，大得有点夸张
                    //现在这个版本显示的内存使用为10+MB
                }
                tmap[s[left]-'\0']++;
                if (tmap[s[left]-'\0'] > 0)
                    count++;
                left++;
            }
        }
        res = (rear == INT_MAX)? "" : string(s.begin()+head, s.begin()+rear);
        return res;
    }
};