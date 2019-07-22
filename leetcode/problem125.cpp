
//v1.0
/* 
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r && !isalpha(s[l]) && !isdigit(s[l])) l++;
        while (l < r && !isalpha(s[r]) && !isdigit(s[r])) r--;
        while (l < r)
        {
            if (isalpha(s[l]))
                s[l] = tolower(s[l]);
            if (isalpha(s[r]))
                s[r] = tolower(s[r]);
            if (s[l] != s[r])
                return false;
            while (l < r && !isalpha(s[++l]) && !isdigit(s[l]));
            while (l < r && !isalpha(s[--r]) && !isdigit(s[r]));
        }
        return true;
    }
};
*/

//v2.0
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r && !isalnum(s[l])) l++;   //直接用isalnum 来判断是否是字母或数字
        while (l < r && !isalnum(s[r])) r--;
        while (l < r)
        {
            if (tolower(s[l]) != tolower(s[r]))     //即使是数字，如果原来相等的话 tolower 以后也相等，因此不用分开字母和数字的情况讨论
                return false;
            while (l < r && !isalnum(s[++l]));
            while (l < r && !isalnum(s[--r]));
        }
        return true;
    }
};