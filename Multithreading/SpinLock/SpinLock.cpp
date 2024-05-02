#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
std::atomic_flag flag = ATOMIC_FLAG_INIT;

void task(int n)
{
    //spin lock
    //test_and_set() return true if another thread set the flag
    //return false if this thread set the flag
    while(flag.test_and_set()) {}

    //critical session
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout <<"I'm task with argument" << n << std::endl;
    //clear the flag
    flag.clear();
}

int main()
{
    std::vector<std::thread> thr_vector;
    for(int i=0; i<10; i++)
    {
        thr_vector.push_back(std::thread(task, i));
    }

    for(int i=0; i<10; i++)
    {
        thr_vector[i].join();
    }

    return 0;
}