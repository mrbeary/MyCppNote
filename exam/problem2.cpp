#include <iostream>
#include <vector>
#include <algorithm>

/*
*       简易麻将游戏：有数字1-9，每个数字4张，共36张牌，吃胡：一对对子（一对同样的数字）+四组刻子或顺子
        给出手牌， 判断抽到哪些牌可以吃胡
        输入：13个已排序的数字，表示手牌
        输出：抽到那张牌可以吃胡（若有多个则输出全部，若无则输出0）

*
*/
using namespace std;
class Solution{
private:
    int deck[10];
    int hand[10];
    int n;
    vector<int> result;
    bool isResult;
public:
    void Initialize()
    {
        result.clear();
        for (int i = 1; i <= 9; i++)
        {
            hand[i] = 0;
            deck[i] = 4;
        }
        n = 0;
        for (int i = 1; i <= 13; i++)
        {
            int tmp;
            cin >> tmp;
            hand[tmp]++;
            deck[tmp]--;
            n++;
        }
    }

    void Judge()
    {
        Initialize();
        for (int i = 1; i <= 9; i++)
        {
            isResult = false;
            if (deck[i] > 0)
            {
                deck[i]--;
                hand[i]++;
                n++;
                judge(i);
                deck[i]++;
                hand[i]--;
                n--;
            }
        }
        if (result.size() == 0)
            cout << 0;
        else
        {
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << ' ';
        }
        
    }

    void judge(int & i)
    {
        
        if (n == 0)
        {
            isResult = true;
            result.push_back(i);
        }
        else if (n == 14)
        {
            for (int p = 1; p <= 9; p++)
            {
                if (hand[p] >= 2)
                {
                    hand[p] -= 2;
                    n -= 2;
                    judge(i);
                    n += 2;
                    hand[p] += 2;
                }
                if (isResult)
                    return;
            }
        }
        else
        {
            for (int j = 1; j <= 9; j++)
            {
                if (hand[j] >= 3)
                {
                    hand[j] -= 3;
                    n -= 3;
                    judge(i);
                    n += 3;
                    hand[j] += 3;
                }
                if (j <= 7 && hand[j] >= 1 && hand[j + 1] >= 1 && hand[j + 2] >= 1)
                {
                    n -= 3;
                    hand[j]--;
                    hand[j + 1]--;
                    hand[j + 2]--;
                    judge(i);
                    hand[j + 2]++;
                    hand[j + 1]++;
                    hand[j]++;
                    n += 3;
                }
                if (isResult)
                    return;
            }
        }
        
    }
};

int main()
{
    Solution s;
    s.Judge();
    return 0;
}