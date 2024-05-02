#include <iostream>
#include <thread>
#include <future>

void producer(std::promise<int>& px)
{
    try
    {
        //1.producer throw
        throw std::exception();
    }
    catch(const std::exception& e)
    {
        //2.producer catch
        std::cout <<"producer catch\n";
        //3.producer stored exception in shared state
        px.set_exception(std::current_exception());
    }
    
    /* set exception with std::make_exception_ptr
    px.set_exception(std::make_exception_ptr(std::out_of_range("nop")));
    */
}

void consumer(std::future<int>& fx)
{
    std::cout <<"in future\n";
    try
    {
        //4.consumer call get() to re-throw the exception
        int x = fx.get();
    }
    //5.consumer catched exception
    catch(const std::exception& e)
    {
        
        std::cout<<"consumer catched\n";
        std::cerr << e.what() << '\n';
    }
   
}

int main()
{
    //creat a promise object => 1 future object is also created
    std::promise<int> pro;
    //get future object from promise object
    std::future<int> fut = pro.get_future();
    std::thread thr_pro(producer, std::ref(pro));
    std::thread thr_fut(consumer, std::ref(fut));

    thr_pro.join();
    thr_fut.join();
    std::cout <<"end\n";
    return 0;
}