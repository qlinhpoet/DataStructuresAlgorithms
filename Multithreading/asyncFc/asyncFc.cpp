#include <iostream>
#include <future>
#include <thread>
#include <string>
int getValue(int x)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return ++x;
}

int task()
{
    std::cout <<"excuting task() in thread " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 42;
}

void func(const std::string& option)
{
    std::future<int> result;

    if(option == "asynch")
        result = std::async(std::launch::async, task);
    else if(option == "deferred")
        result = std::async(std::launch::deferred, task);
    else
        result = std::async(task);
    
    std::cout <<"calling async with option " <<option<<"\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout <<"task result " <<result.get()<<std::endl;
}

int main()
{
    std::future<int> fut = std::async(std::launch::async ,getValue, 10);
    while(std::future_status::ready != fut.wait_for(std::chrono::seconds(1)))
    {
        std::cout <<"waitting\n";
    }
    std::cout << fut.get() <<std::endl;

    std::cout <<"main thread is " <<std::this_thread::get_id() <<"\n";
    //creat new thread and then excute task
    func("async");
    //excute task() in current thread, task is excuted after call get()
    func("deferred");
    //creat new thread and then excute task
    func("default");

    return 0;
}