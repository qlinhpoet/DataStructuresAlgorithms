#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <vector>

class Vector
{
    private:
    std::mutex mutex_mem;
    std::vector<int> vec;
    public:

    void push_back(const int& x)
    {
        mutex_mem.lock();
        vec.push_back(x);
        mutex_mem.unlock();
    }

    void print()
    {
        mutex_mem.lock();
        for(auto i : vec)
        {
            std::cout << i <<", ";
        }
        mutex_mem.unlock();        
    }
};
void func(Vector& v)
{
    for(int i=0; i<5; i++)
    {
        v.push_back(i);
    }

        for(int i=0; i<5; i++)
    {
        v.print();
    }
}

int main()
{
    Vector vec;
    std::thread thr1(func, std::ref(vec));
    thr1.join();
    return 0;

}