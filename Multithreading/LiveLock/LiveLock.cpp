#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

std::mutex mut1, mut2;

void funcA()
{
    bool locked = false;
    while(locked == false)
    {
        std::lock_guard<std::mutex> lk(mut1);
        std::cout<<"After you, B\n";
        std::this_thread::sleep_for(2s);
        locked = mut2.try_lock();
    }
    if(locked)
    {
        std::cout << "thread A locked 2 mutexes\n";
    }
}

void funcB()
{
    std::this_thread::sleep_for(10ms);
    bool locked = false;
    while(locked == false)
    {
        std::lock_guard<std::mutex> lk(mut2);
        std::cout<<"After you, A\n";
        std::this_thread::sleep_for(2s);
        locked = mut1.try_lock();
    }
    if(locked)
    {
        std::cout << "thread A locked 2 mutexes\n";
    }
}

int main()
{
    std::thread thr1(funcA);
    std::this_thread::sleep_for(10ms);
    std::thread thr2(funcB);

    thr1.join();
    thr2.join();
    return 0;
}