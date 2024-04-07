#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <vector>
//global mutex object
std::mutex task_mutex;

void task(const std::string& str)
{
    for(int i=0; i<5; i++)
    {
        //try and wait until lock mutex before enter the critical session
        task_mutex.lock();
        //
        std::cout<< str[0] << str[1] << str[2] << std::endl;
        //unlock the mutex after critical session
        task_mutex.unlock();
    }
}

int main()
{
    std::thread thr1(task, "hello");
    std::thread thr2(task, "good");
    std::thread thr3(task, "bye");

    thr1.join();
    thr2.join();
    thr3.join();

    return 0;
}
