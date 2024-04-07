#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
int value;

std::mutex task_mutex;

void increments()
{
    for(int i; i<100000; i++)
    {
        value++;
    }
}

int main()
{
    //creat a vector, type thread
    std::vector<std::thread> tasks;
    //push 10 thread into vector
    for(int i=0; i<10; i++) tasks.push_back(std::thread{increments});
    //
    for(int i=0; i<10; i++) tasks[i].join();
    std::cout << value;
    return 0;
}