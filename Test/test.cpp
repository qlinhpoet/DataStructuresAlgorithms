#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

//std::atomic<int> x = 0;
std::atomic<int> x = {0};
//int x;
std::mutex mut;

void increment()
{
    for(int i=0; i<100000; i++)
    {
        std::lock_guard<std::mutex> lck_guard(mut);
        x++;
    }

}

int main()
{
    std::thread thr1(increment);
    std::thread thr2(increment);
    
    thr1.join();
    thr2.join();
    std::cout <<x<<std::endl;
    return 0;
}