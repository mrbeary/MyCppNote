

//方案1 暴力遍历所有情况，虽然通过了所有样例，但耗时长
/* 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int buy = 0; buy < prices.size(); buy++)
        {
            for (int sell = buy; sell < prices.size(); sell++)
            {
                result = max((prices[sell]-prices[buy]), result);
            }
        }
        return result;
    }
};

*/

//方案2
//主要思路：遍历过程中，找出当前点左侧的最小值，最大利润就是 当前点的价钱-最小值 与 目前最大利润 较大的一个 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int minprice = INT_MAX;
        for (int i = 0; i < prices.size(); ++i)   //只遍历一遍
        {
            if (prices[i] < minprice)
                minprice = prices[i];
            result = max(result, prices[i]-minprice);
        }
        return result;
    }
};