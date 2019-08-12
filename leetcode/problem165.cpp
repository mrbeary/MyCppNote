


class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        v1 = breakIntoVector(version1);
        v2 = breakIntoVector(version2);
        int i = 0;
        while (i < v1.size() && i < v2.size())
        { //逐为比较
            if (v1[i] == v2[i])
            {
                i++;
                continue;
            }
            else if (v1[i] > v2[i])
            {
                return 1;
            }
            else
                return -1;
        }
        if (i == v1.size() && i == v2.size()) //同时到达结尾，说明相等
            return 0;
        if (i == v1.size()) //对应version2比较长的情况
        {
            while (i < v2.size())
            {
                if (v2[i] != 0)
                    return -1;
                i++;
            }
            return 0;
        }
        while (i < v1.size()) //对应version1比较长的情况
        {
            if (v1[i] != 0)
                return 1;
            i++;
        }
        return 0;
    }
    
private:
    vector<int> breakIntoVector(string &version) //这个函数将字符串以 . 为间隔进行拆分，例如“1.2.1” 会被拆成 [1,2,1]返回
    {
        vector<int> res;
        int i = 0;
        while (i < version.size())
        {
            int j = i;
            for (; j < version.size() && version[j] != '.'; j++);
            int tmp = 0;
            for (int k = i; k < j; ++k)
            {
                tmp = tmp * 10 + version[k] - '0';
            }
            res.push_back(tmp);
            i = j+1;
        }
        return res;
    }
};