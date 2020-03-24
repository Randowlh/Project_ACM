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

    thread t(th_function);
    t.join();

    return 0;
}