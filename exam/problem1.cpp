#include <iostream>
#include <vector>
using namespace std;

/*
问题：
    每头母牛有10年寿命（第10年还活着），假设出生时算一岁，母牛在3-7岁时每年年初会
    产下一头小母牛，小母牛同样有10年寿命，3-7岁每年年初会产下一头小母牛，如此重复，
    问：第n年有多少头活着的母牛？
输入：一个大于等于1的正整数n    输出：第n年活着的母牛
例子1：输入   1     输出  1
例子2：输入   5     输出  5
例子3：输入   8     输出  20
例子4：输入   12    输出  123
*/
class Solution{
/*
    1.数组years用于储存每年出生的母牛数，由1开始算，例如第1年有一头母牛出生，
    则years[1] = 1， 第二年没有母牛出生，years[2] = 0
    可以用递归的方式计算第n年出生的母牛数 years[n]
    拥有以下关系式：years[n] = years[n-1] + years[n-2] - years[n-7]
    2.数组alive 用于储存对应第n年活着的母牛数，例如第一、二年都只有一头母牛
    活着，则 alive[1] = alive[2] = 1
    可以用以下关系式计算 alive[n]
    alive[n] = alive[n-1] + years[n] - years[n - 10]
*/
private:
    vector<int> years;
    vector<int> alive;
public:
    Solution()
    {
        years = {0,1,0};
        alive = {0, 1, 1};
    }
    int HowMany(int y)
    {
        while (y > years.size() - 1)
        {
            int currentYear = years.size();
            int f1,f2,f7;
            f1 = years[currentYear - 1];
            f2 = years[currentYear - 2];
            if (currentYear - 7 < 1)
                f7 = 0;
            else
                f7 = years[currentYear - 7];
            years.push_back(f1 + f2 - f7);
        }
        while (y > alive.size() - 1)
        {
            int current = alive.size();
            int die;
            if (current >= 11)
                die = years[current - 10];
            else
                die = 0;
            alive.push_back(alive[current - 1] + years[current] - die); 
        }
        return alive[y];
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    cout << s.HowMany(n) << endl;
    cin.get();
    cin.get();
    return 0;
}