#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>

//std::shared_mutex' is only available from C++17 onwards
std::shared_mutex shmut;

void hello()
{
    //creat a shared_lock object
    //lock shmut by shared_lock
    std::shared_lock shared_lk(shmut);
    //.....
}

int main()
{
    return 0;
}