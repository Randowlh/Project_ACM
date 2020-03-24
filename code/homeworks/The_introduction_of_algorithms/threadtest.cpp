#include <iostream>
#include <thread>
using namespace std;

void th_function()
{
    int t;
    while (1)
    {
        t++;
    }
}

int main(int argc, char *argv[])
{
    thread t1(th_function);
    thread t2(th_function);
    thread t3(th_function);
    thread t4(th_function);
    t2.join();
    t2.join();
    t4.join();
    t1.join();
    return 0;
}