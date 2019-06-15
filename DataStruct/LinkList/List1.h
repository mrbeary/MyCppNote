#ifndef __LIST1__H__
#define __LIST1__H__

/*
*   基于动态数组实现的线性表
*/

#include<iostream>
using namespace std;

template <typename T>
class List{
private:
    T *arr;
    int Capacity;
    int CurrentSize;
public:
    List() {Capacity = CurrentSize = 0;}
    List(int Cap) {arr = new T[Cap]; Capacity = Cap; CurrentSize = 0;}
    ~List() {delete [] arr;}
    List(List<T> & l);
    const List<T> & operator=(const List<T> & l);
    bool Empty() {return CurrentSize == 0;}
    void Insert(int pos, T value);
    void Delete(int pos);
    void Traverse();
};

template<typename T>
List<T>::List(List<T> & l)
{
    arr = new T[l.Capacity];
    CurrentSize = l.CurrentSize;
    Capacity = l.Capacity;
    for (int i = 0; i < CurrentSize; i++)
    {
        arr[i] = l.arr[i];
    }
}

template<typename T>
const List<T> & List<T>::operator=(const List<T> & l)
{
    if (this == &l)
        return *this;
    delete [] arr;
    arr = new T[l.Capacity];
    Capacity = l.Capacity;
    CurrentSize = l.CurrentSize;
    for (int i = 0; i < CurrentSize; i++)
    {
        arr[i] = l.arr[i];
    }
    return *this;
}

template<typename T>
void List<T>::Insert(int pos, T value)
{
    if (CurrentSize >= Capacity)
    {
        cout << "List is full" << endl;
        exit(1);
    }
    else if (pos < 0 || pos > CurrentSize)
    {
        cout << "Wrong index" << endl;
        return;
    }
    for (int i = CurrentSize; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    CurrentSize++;
}

template<typename T>
void List<T>::Delete(int pos)
{
    if (CurrentSize == 0)
    {
        cout << "List is empty" << endl;
        exit(1);
    }
    else if (pos < 0 || pos >= CurrentSize)
    {
        cout << "Wrong index" << endl;
        return;
    }
    CurrentSize--;
    for (int i = pos; i < CurrentSize; i++)
    {
        arr[i] = arr[i + 1];
    }
}

template<typename T>
void List<T>::Traverse()
{
    for (int i = 0; i < CurrentSize; i++)
    {
        cout << arr[i] << ' ';
    }
}

#endif