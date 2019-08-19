#include <iostream>
#include <vector>
#include "myheader.h"

class Heap {
public:
    Heap()
    {
        heap = {0};
    }
    void makeHeap()
    {
        
    }
    void pushHeap()
    {

    }
private:
    vector<int> heap;
    void upstair(int index)
    {
        while (index != 1 && heap[index] > heap[index / 2])
        {
            swap(heap[index], heap[index / 2]);
            index = index / 2;
        }
    }
    void downstair(int index)
    {
        while (index * 2 < heap.size()) //不为叶子节点时
        {
            int tmp = index;
            
        }
    }
};

