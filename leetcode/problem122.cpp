
//V1.0
/* 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int result = 0;
        int curprofit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minprice)
            {
                result += curprofit;
                curprofit = 0;
                minprice = prices[i];
            }
            else
            {
                int tmp = prices[i] - minprice;
                if (tmp < curprofit)
                {
                    minprice = prices[i];
                    result += curprofit;
                    curprofit = 0;
                }
                else
                    curprofit = tmp;
            }
        }
        result += curprofit;
        return result;
    }
};*/

//V2.0 循环里的条件判断有点重合了，可以再精简一点
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int result = 0;
        int curprofit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            int tmp = prices[i] - minprice;
            if (tmp < curprofit)
            {
                minprice = prices[i];
                result += curprofit;
                curprofit = 0;
            }
            else
                curprofit = tmp;
        }
        result += curprofit;
        return result;
    }
};

// 在discuss里看到一个超级简练的答案
// 他的主要思路是 “今天买，明天卖”，如果利润为正，就加入到总利润；利润为负就总利润加0
/*
class Solution {
public:
    int maxProfit(vector<int> & prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
            res += max(prices[i] - prices[i-1], 0);
        return result;
    }
};
 */