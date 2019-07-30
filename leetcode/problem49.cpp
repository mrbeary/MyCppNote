


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;  //利用排好序的字符串作为map的key
        for (int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());  //对字符串 tmp 进行排序
            if (m.find(tmp) != m.end())
                m[tmp].push_back(strs[i]);  //在m里面找一下有没有与tmp是一组的key，有的话直接加入
            else
            {
                vector<string> stmp; //没有的话新建一个key
                stmp.push_back(strs[i]);
                m[tmp] = stmp;
            }
        }
        vector<vector<string>> res;
        map<string, vector<string>>::iterator iter = m.begin();
        //将m里面的内容放到结果res
        while (iter != m.end())
        {
            res.push_back(iter->second);
            iter++;
        }
        return res;
    }
};