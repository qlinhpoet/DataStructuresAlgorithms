#include <iostream>
#include <thread>
#include <atomic>

std::atomic_flag lock = ATOMIC_FLAG_INIT;
//std::atomic_flag lock = {0};
int main()
{
    std::atomic<int> x {0};
    std::cout << x << std::endl;

    //replace object 'value with argument
    x.store(5);
    std::cout << x << std::endl;

    //return object'value
    std::cout << x.load() << std::endl;

    //replace object 'value with argument
    //but return previous value
    std::cout << x.exchange(10) << std::endl;
    std::cout << x << std::endl;

    x++;
    std::cout << x.load() << std::endl;
    x.fetch_add(2);
    std::cout << x.load() << std::endl;
    
    //atomic flag
    return 0;


    
}