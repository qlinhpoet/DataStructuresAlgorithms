#include <iostream>
#include <future>
#include <chrono>

int main()
{
    //packaged task object
    //the callable object is a lambda expression
    //the callable object take int and int argument and return int
    std::packaged_task<int(int, int)>ptask([](int a, int b)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return a+b;
    }
    );

    //get the future is associated with promise object
    std::future<int> fut = ptask.get_future();

    ptask(6,7);

    //call get() to receive the result of packaged task
    std::cout <<"6 + 7 = "<<fut.get() << std::endl;

    /* std::packaged task in new thread
    std::thread thr(std::move(ptask), 10, 7);
    std::cout <<"10 + 7 = "<<fut.get() << std::endl;
    thr.join();
    */
    return 0;
}