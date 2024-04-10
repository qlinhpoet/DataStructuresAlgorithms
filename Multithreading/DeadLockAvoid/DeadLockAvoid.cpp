#include <iostream>
#include <mutex>
#include <thread>
std::mutex mut1, mut2, mut3;

void funcA()
{
    std::unique_lock<std::mutex> lck1(mut1, std::defer_lock);
    std::unique_lock<std::mutex> lck2(mut2, std::defer_lock);
    std::unique_lock<std::mutex> lck3(mut3, std::defer_lock);

    int index = std::try_lock(mut1, mut2, mut3);

    if(index == -1)
    {
        //lock success
        std::cout <<"lock success\n";
    }
    else
    {
        std::cout << "cannot lock mutex " << index <<std::endl;
    }
    std::cout <<"locked:1, unlock:0\n";
    std::cout <<"is mut1 locked?? => " << (mut1.try_lock() == 0) << std::endl;
    std::cout <<"is mut2 locked?? => " << (mut2.try_lock() == 0) << std::endl;
    std::cout <<"is mut3 locked?? => " << (mut3.try_lock() == 0) << std::endl;

}

int main()
{
    mut2.lock();
    std::thread thr1(funcA);
    thr1.join();

    return 0;
}