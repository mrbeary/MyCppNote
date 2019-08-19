#include<iostream>
#include<thread>
using namespace std;
void addInt(int i, int j)
{
    cout << i + j << endl;
}
void updateInt(int &i)
{
    i++;
}
void doNothing() {}

int main()
{
    cout << this_thread::get_id() << endl;
    thread t(doNothing);
    cout << t.get_id() << endl;
    t.detach();
    return 0;
}