

#include <iostream>
#include <thread>

using namespace std;

class DoNothing {
public:
    operator()()
    {
        cout << "Oh! NO!\n";
    }
};

void printSomething()
{
    cout << "Hi! Man\n" << endl;
}

int main()
{
    class DoNothing d;
    thread th(d);
    th.join();
    return 0;
}