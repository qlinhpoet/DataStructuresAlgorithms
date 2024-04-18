#include <iostream>
#include <thread>
#include <future>
#include <mutex>

void producer(std::promise<int>& px)
{
    //produce the result
    int x = 42;
    //store result in shared data
    px.set_value(x);
}

//consumer task function take a std::future object as argument
void consumer(std::future<int>& fx)
{
    //Returns the value stored in the shared state (or throws its exception) when the shared state is ready.
    //If the shared state is not yet ready  the function blocks the calling thread and waits until it is ready.
    int x = fx.get();
    std::cout<<x<<std::endl;
}



int main()
{
    //creat 1 promise object
    //constructor also creat 1 future object
    //2 objects are associated
    std::promise<int> prom;

    //future object is get from promist object
    std::future<int> fut = prom.get_future();

    std::thread thr_producer(producer, std::ref(prom));
    std::thread thr_consumer(consumer, std::ref(fut));

    thr_producer.join();
    thr_consumer.join();
    return 0;
}