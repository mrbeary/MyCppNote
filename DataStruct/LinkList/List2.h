#ifndef __LIST2__H__
#define __LIST2__H__

#include <iostream>
using namespace std;

namespace MyList{

    template <typename T>
    class Node{
        public:
        T m_data;
        Node<T> * m_next;
        public:
        Node(T data, Node<T> * next = nullptr) : m_data(data), m_next(next) {}
        Node() : m_next(nullptr) {}
    };

    template <typename T>
    class List{
    private:
        int CurrentSize;
        Node<T> * head;
    public:
        List();
        ~List();
        List(List<T> & l);
        const List<T> & operator=(const List<T> & l);
        bool Empty() const;
        void Traverse();
        void Insert(int pos, T value);
        void Delete(int pos);
    };

    template<typename T>
    List<T>::List() : head(nullptr), CurrentSize(0)
    {}

    template<typename T>
    List<T>::~List()
    {
        Node<T> * tmp = head;
        while (head)
        {
            head = head->m_next;
            delete tmp;
            tmp = head;
        }
    }

    template<typename T>
    List<T>::List(List<T> & l)
    {
        CurrentSize = l.CurrentSize;
        if (l.head)
        {
            head = new Node<T>(l.head->m_data);
            l.head = l.head->m_next;
        }
        Node<T> * tmp = head;
        while (l.head)
        {
            tmp->m_next = new Node<T>(l.head->m_data);
            tmp = tmp->m_next;
            l.head = l.head->m_next;
        }
    }

    template<typename T>
    const List<T> & List<T>::operator=(const List<T> & l)
    {
        if (this == &l)
            return *this;
        this->~List();
        CurrentSize = l.CurrentSize;
        if (l.head)
        {
            head = new Node<T>(l.head->m_data);
        }
        Node<T> * tmp = head;
        Node<T> * tmp2 = l.head->m_next;
        while (tmp2)
        {
            tmp->m_next = new Node<T>(tmp2->m_data);
            tmp = tmp->m_next;
            tmp2 = tmp2->m_next;
        }
        return *this;
    }

    template<typename T>
    bool List<T>::Empty() const
    {
        return CurrentSize == 0;
    }

    template<typename T>
    void List<T>::Insert(int pos, T value)
    {
        if (pos > CurrentSize || pos < 0)
        {
            cout << "Wrong Index\n";
            return;
        }
        Node<T> * newNode = new Node<T>(value);
        if (pos == 0)
        {
            newNode->m_next = head;
            head = newNode;
        }
        else
        {
            int i = 1;
            Node<T> * prePtr = head;
            while (i != pos)
            {
                prePtr = prePtr->m_next;
                i++;
            }
            newNode->m_next = prePtr->m_next;
            prePtr->m_next = newNode;
        }
        CurrentSize++;
    }

    template<typename T>
    void List<T>::Delete(int pos)
    {
        if (pos >= CurrentSize || pos < 0)
        {
            cout << "Wrong Index" << endl;
            return;
        }
        if (pos == 0)
        {
            Node<T> * toBeDelete = head;
            head = head->m_next;
            delete toBeDelete;
        }
        else
        {
            int i = 1;
            Node<T> * prePtr = head;
            while (i != pos)
            {
                prePtr = prePtr->m_next;
                i++;
            }
            Node<T> * toBeDelete = prePtr->m_next;
             prePtr->m_next = prePtr->m_next->m_next;
             delete toBeDelete;
        }
        CurrentSize--;
    }
    
    template<typename T>
    void List<T>::Traverse()
    {
        Node<T> * tmp = head;
        while (tmp)
        {
            cout << tmp->m_data << ' ';
            tmp = tmp->m_next;
        }
    }
}
#endif