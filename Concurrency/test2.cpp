#include <iostream>
#include <thread>
using namespace std;


class Func {
public:
    int &i; //类Func有一个类型为 int 引用的数据成员
    Func(int &i_) : i(i_){}  //构造函数
    operator()() //重载括号运算符
    {
        cout << i << endl;
        for (int j = 0; j < 999999; ++j)
        {
            if (j % 100000 == 0)
            {
                cout << i << endl;
            }
        }
            
        //i++;
    }
};

void oops()
{
    int local_int = 0;
    Func my_func(local_int);
    thread my_thread(my_func);
    my_thread.join();
    //cout << local_int << endl;
    return;
}

int main()
{
    thread th(oops);
    th.join();
    return 0;
}