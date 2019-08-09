


class Solution {
public:
    string reverseWords(string s) {
        vector<string> store;
        int i = 0;
        while (i < s.size())
        {
            if (s[i] == ' ')
            {
                i++;
                continue;
            }
            int j = i;
            for (; j < s.size() && s[j] != ' '; j++);
            string word = s.substr(i, j - i);
            store.push_back(word);
            i = j;
        }
        string res;
        for (i = store.size()-1; i >= 0; i--)
        {
            res = res + store[i] + ' ';
        }
        res.erase(res.end()-1);
        return res;
    }
};