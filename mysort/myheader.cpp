#include "myheader.h"

vector<int> buildVectorFromRandom(int n)
{
    vector<int> vt(n);
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        vt[i] = rand() % n;
    }
    return vt;
}

void shuffle(vector<int> & vt)
{
    srand(time(0));
    for (int i = 0; i < vt.size(); i++)
    {
        int swapIndex = rand() % vt.size();
        swap(vt[i], vt[swapIndex]);
    }
}

void printVector(const vector<int> & vt)
{
    for (auto i : vt)
        cout << i << ' ';
    cout << endl;
}