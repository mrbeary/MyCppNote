#include<iostream>
#include<fstream>
#include<time.h>
#include <vector>
/*
*   问题：26个字母中，所有6个字母的全排列
*       
*/
using namespace std;

void permutation(char * word, int len, int start);   //用于产生字母的全排列

void choose(char * word, int start, int left);       //用于从 26 个字母中选出 6 个字母  ， 此函数用递归方法（方案1）

void combine(char * wordList, int total, int select);     //同样用于 26 个字母中选出 6 个字母， 但没有用到递归（方案2）

/*
*   我的解题思路： 先每次从 26 个字母中选 6 个出来， 然后让这 6 个字母产生全排列
*
*
*/
long long resultCount = 0;   // 全局变量，用于对结果进行计数， 原本想将排列结果输出的，但数量太大了，所以就只作计数
char alphabet[26];     // 字母表
int chooseCount = 0;
int main()
{
    int t1 = time(0);
    for (int i = 0; i < 26; i++)
        alphabet[i] = 'a' + i;  //这循环结束以后 alphabet 中就是 26 个小写字母
    combine(alphabet, 26, 6);  //主要功能在这实现
    cout << resultCount << endl;  //输出结果数量，按照数学计算，理论结果应该是 165765600
    int t2 = time(0);
    cout << "Totaly cost " << t2 - t1 << " s" << endl;  //输出程序运行的时间
    cin.get();
    return 0;
}

void permutation(char * word, int len, int start)
{
    if (start == len - 1)
    {
        resultCount++;
        return;
    }
    else
    {
        for (int i = start; i < len; i++)
        {
            swap(word[start], word[i]);
            permutation(word, len, start + 1);
            swap(word[start], word[i]);
        }
    }
    
}

void choose(char * word, int start, int left)
{
    
    if (left == 0)
    {   
        permutation(word, 6, 0);
        return;
    }
    for (int i = start; i <= 26 - left; i++)
    {
        word[6 - left] = alphabet[i];
        choose(word, i + 1, left - 1);
    }
}

void combine(char * wordList, int total, int select)
{
    vector<int> p(select, -1);
    int i = 0;
    while (i >= 0)
    {
        p[i]++;
        if (p[i] > total - 1)
        {
            --i;
        }
        else if (i == select - 1)
        {
            
            char * word = new char[select];
            for (int j = 0; j < select; j++)
            {
                word[j] = wordList[p[j]];
            }
            permutation(word, select, 0);
            delete [] word;
        }
        else
        {
            ++i;
            p[i] = p[i-1];
        }
        
    }
}