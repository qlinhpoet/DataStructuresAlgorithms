#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

//std::shared_ptr has an atomic reference counter
std::shared_ptr<int> sharedptr = std::make_shared<int>(42);

std::mutex mut;
void func1()
{
    //copy shared_ptr - safe
    std::shared_ptr<int> shptr1 = sharedptr;
    //access and changed data - must be protected
    std::lock_guard<std::mutex> lck(mut);
    *shptr1 = 5;
}

void func2()
{
    //copy shared_ptr - safe
    std::shared_ptr<int> shptr2 = sharedptr;
}
int main()
{
    std::cout <<"shared data " << *sharedptr <<std::endl;  
    std::thread thr1(func1);
    std::thread thr2(func2);

    thr1.join();
    thr2.join();

    std::cout <<"shared data " << *sharedptr <<std::endl;

}
