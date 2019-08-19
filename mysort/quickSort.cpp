#include "myheader.h"

void quickSort(vector<int>& vt, int start, int end);
void test();
int main()
{
    test();
}
/*
void quickSort(vector<int> & vt, int start, int end)
{
    if (end - start <= 0)
        return;
    int provit = vt[start];
    int left = start + 1, right = end;
    while (left < right)
    {
        while (vt[left] <= provit)
        {
            left++;
        }
        while (vt[right] > provit)
        {
            right--;
        }
        //if (right > left && right >= start && left <= end)
        if (right > left)
        {
            swap(vt[left], vt[right]);
        }
    }
    swap(vt[right], vt[start]);
    quickSort(vt, start, right - 1);
    quickSort(vt, right + 1, end);
}*/

void quickSort(vector<int>& nums, int start, int end)
{//数组要传入引用
    if (start >= end)
        return;
    int provit = nums[start];
    int left = start + 1, right = end;
    while (left < right)
    {
        while (left < right && nums[left] <= provit) left++; //等于的情况放在这里处理，还要加上left<right的条件，防止数组越界
        while (nums[right] > provit) right--;
        if (left < right)
            swap(nums[left], nums[right]);
    }
    swap(nums[start], nums[right]);
    quickSort(nums, start, right - 1);
    quickSort(nums, right + 1, end);
}

void test()
{
    vector<int> nums = buildVectorFromRandom(11);
    shuffle(nums);
    printVector(nums);
    quickSort(nums, 0, nums.size() - 1);
    printVector(nums);
    vector<int> num = {1,1,1,1,1,1};
    quickSort(num, 0, num.size() - 1);
    printVector(num);
}