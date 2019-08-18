

/*
双指针法
分别指向一头一尾
接的雨水量受左右两条边中较短的一侧限制

*/
class Solution {
public:
    int trap(vector<int>& height) {
        int maxleft = 0, maxright = height.size() - 1;
        int curleft = maxleft, curright = maxright;
        int res = 0;
        while (curleft <= curright)
        {
            if (height[maxleft] < height[maxright])
            { //如果左边的边比较短，就在左半侧“搞事情”
                if (height[curleft] < height[maxleft])
                {
                    res += height[maxleft] - height[curleft]; 
                }
                else
                {
                    maxleft = curleft;
                }
                curleft++;
            }
            else
            { //否则就在右半侧搞事
                if (height[curright] < height[maxright])
                {
                    res += height[maxright] - height[curright];
                }
                else
                    maxright = curright;
                curright--;
            }
        }
        return res;
    }
};