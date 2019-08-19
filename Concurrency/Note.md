#并发编程
***
##启动线程
* 包含头文件 \<thread>
* 构造 std::thread对象，传入一个可调用(callable)对象
* 通过创建一个thread对象来开始一个线程
```c++
#include <iostream>
#include <thread>

using namespace std;

void printSomething()
{
    cout << "Hi! Man\n" << endl;
}

int main()
{
    thread th(printSomething);
    return 0;
}
```
* 编译运行，需要加上 -pthread 和 --std=c++11，因为在windows平台，所以生成的是exe文件
```
g++ ./test1.cpp -pthread --std=c++11
./a.exe
```
* *直接这样运行好像有点问题*，linux下的话会显示：
```
terminate called without an active exception
Aborted
```
* 需要 `return 0;` 之前加上一句 `th.join();`来等待线程的结束，变成：
```
thread th(printSomething);
th.join();
return 0;
```
* 现在编译运行就会看到程序输出一句`Hi! Man`并正常退出
* 传入thread构造函数是**可调用(callable)类型**，所以尝试一下传入**重载了括号运算符的对象**试试
* 先搞一个类
```c++
class DoNothing {
public:
    operator()()
    {
        cout << "Oh! NO!\n";
    }
};
```
* 然后main函数换成：
```c++
int main()
{
    class DoNothing d;
    thread th(d);
    th.join();
    return 0;
}
```
* 编译运行
* 嗯嗯，现在能输出一句`Oh! No!` 并正常退出

## 等待线程完成
* 一旦开始了线程，就需要显示地决定是要等待它完成(`join`)，还是让它自个运行(`detach`)
* 如果在`thread`对象被销毁前未作决定，那么程序会被终止（**std::thread  的析构函数调用std::terminate()**)，上面我们第一次未加`th.join()`时运行程序，最后出错，应该就是这个原因
* 我们只需在`thread`对象被销毁之前做出这个决定即可---线程本身可能在我们分离或结合它之前早就已经结束了
* 如果不等待线程完成，那么需要**确保通过该线程访问的数据是有效的**，直到该线程结束为止
* 可能遇到这种问题的一种情况：当线程函数持有局部遍历的指针或引用，且当函数退出的时候线程尚未完成时。比如说：
```c++
class Func {
public:
    int &i; //类Func有一个类型为 int 引用的数据成员
    Func(int &i_) : i(i_){}  //构造函数
    void operator()() //重载括号运算符
    {
        for (int j = 0; j < 99999; ++j)
            i /= 2;
    }
};

void oops()
{
    int local_int = 0;
    Func my_func(local_int);//my_func里的i是local_int的引用
    thread my_thread(my_func);
    my_thread.detach();//分离线程，如果这个函数退出时my_thread还没完成，里面的i就失效了
}

int main()
{
    thread th(oops);
    th.join();
    return 0;
}
```

## 在后台运行线程
* 在`std::thread`对象上调用`detach()`会把线程丢在后台运行，也没有直接的方法与之通信，也不再可能等待该线程完成；如果一个线程成为分离的，获取一个引用它的`std::thread`对象也是不可能的，所以它也不再能被结合。
* 意思就是如果`thread`对象调用了`detach`，那就不能`join`了。比如下面一段代码：
```c++
#include <iostream>
#include <thread>

using namespace std;

void doNothing()
{}

int main()
{
    thread th(doNothing);
    cout << boolalpha << th.joinable() << endl; //这里输出的是true
    th.detach();
    cout << boolalpha << th.joinable() << endl; //调用了detach()以后就变成false了
    return 0;
}
```
* 为了从一个`std::thread`对象中分离线程，必须有一个线程供分离。
* 不能再一个没有执行相关联的`std::thread`对象上调用`detach()`。这对`join()`也是同样的要求
* 即只能在`t.joinable()`返回true时，才能为一个`std::thread`对象`t`调用`t.join()`或`t.detach()`。

##传递参数给线程函数
* 上面创建线程的函数都是无参函数，现在试试传递参数。
```c++
#include<iostream>
#include<thread>
using namespace std;
void addInt(int i, int j)
{
    cout << i + j << endl;
}
int main()
{
    int x = 0, y = 10;
    thread th(addInt, x, y); //这里实际上就是调用 addInt(x, y);
    th.join();
    return 0;
}
```
####传入引用
```c++
void updateInt(int &i) { i++; }
int main()
{
    int x = 0;
    thread th(updateInt, ref(x)); 
    th.join();
    return 0;
}
```
* 这里需要用`ref()`来包装参数，告诉`std::thread`的构造函数，传入的是引用

## 转移线程的所有权
* 一个特定执行线程的所有权可以在`std::thread`实例之间移动，比如：
```c++
void doSomething();
void doOhterThing();
thread t1(doSomething); //创建一个线程t1
thread t2 = move(t1);  //将原本运行在t1上的线程的 所有权 交给t2,现在t1没有关联线程
t1 = thread(doOtherThing); //t1关联到一个新线程
thread t3;
t3 = move(t2); //t2的线程的所有权交给t3
t1 = move(t3); //not allow,因为t1目前已有关联线程
```
* 使用`std::move()`来**转移线程的所有权**

## 在运行时选择线程的数量
* `std::thread::hardware_concurrency()`函数返回一个对于指定程序执行时能够真正并发运行的线程数量的指示。例如在多核系统上它可能是CPU核心的数量
```c++
cout << thread::hardware_concurrency() << endl;
```
* 比如在我的两核四线程的电脑上，上面这条语句输出的是4
* 选择最大的创建进程数量可以防止**超额订阅**

## 标识线程
* 线程标识符是`std::thread::id`类型的，有两种获取方式。
* 可以通过`std::thread`对象调用`get_id()`成员函数来获得，如果`std::thread`对象没有相关联的执行线程，对`get_id()`的调用返回一个默认构造的`std::thread::id`对象，表示“没有线程”
* 当前线程的标识符，可以通过调用`std::thid_thread::get_id()`获得.
```c++
void doNothing() {}

int main()
{
    cout << this_thread::get_id() << endl;
    thread t(doNothing);
    cout << t.get_id() << endl;
    t.detach();
    return 0;
}
```