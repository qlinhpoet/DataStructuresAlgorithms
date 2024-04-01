
//every std::thread object must call join() or detach
#include <iostream>
#include <thread>

class thread_guard
{
    std::thread thr;
public:
    //constructor takes rvalue reference argument (std::thread is move only)
    explicit thread_guard(std::thread&& thr)
    {
        this->thr = std::move(thr);
    }

    ~thread_guard()
    {
        if(thr.joinable())
        {
            //need to join() or detach()
            thr.join();
        }
    }
};

void hello(){       std::cout <<"hello\n";      }

int main()
{
    std::thread thr1(hello);
    //to make sure thread object call join()
    thread_guard thr1_guard(std::move(thr1));
    return 0;
}