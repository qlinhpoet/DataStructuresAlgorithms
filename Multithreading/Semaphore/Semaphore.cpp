#include <iostream>
#include <condition_variable>
#include <thread>
#include <mutex>

class semaphore
{
private:
    std::mutex mut;
    std::condition_variable cv;
    int counter = 0;
public:

    void release()
    {
        std::lock_guard<std::mutex> lck(mut);
        ++counter;
        std::cout <<"counter = " << counter <<std::endl;
        cv.notify_all();
    }

    void acquire()
    {
        //unique lock mut, unlock when call constructor
        std::cout <<"acquiring" <<std::endl;
        std::unique_lock<std::mutex> lck(mut);
        
        while(counter == 0)
        {
            cv.wait(lck);
        }

        counter--;
        //constructor unlock mut but with counter == 0, other acquire() will be blocked

    }

};

int x = 0;
semaphore sem;
void increment()
{
    sem.acquire();
    //sem.acquire();
    x++;
    sem.release();
}

int main()
{
    std::thread thr1(increment);
    std::thread thr2(increment);

    thr1.join();
    thr2.join();

    std::cout <<x<<std::endl;
    return 0;
}