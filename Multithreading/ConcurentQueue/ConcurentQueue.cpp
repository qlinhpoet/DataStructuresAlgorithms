#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
template <class T>
class ConcurentQueue
{
    private:
    std::mutex mut;
    std::queue<T> q;
    std::condition_variable cv;
    public:
    void push(T value)
    {
        
        {
            std::lock_guard<std::mutex> lck(mut);
            std::cerr << "Notifying...\n";
        }
        //notified but predicate still false => cannot break wait()
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::seconds(3));

        
        {
            std::lock_guard<std::mutex> lck(mut);
            q.push(value);
            std::cerr << "pushed...\n";
            std::cerr << "Notifying again...\n";
        }
        //notify with predicate true
        cv.notify_all();
        
    }

    void pop(T& value)
    {
        std::unique_lock<std::mutex> lck(mut);
        std::cout<<"waitting\n";                                
        cv.wait(lck, [this](){ return !q.empty();});
        std::cerr << "front...\n";
        value = q.front();
        q.pop();  
    }
};
int main()
{
    int x = 0;
    ConcurentQueue<int> q;
    //q.push(5);
    

    auto po = [&q, &x](){q.pop(x);};
    auto pu = [&q](){q.push(5);};
    std::thread t1(pu);
    std::thread t2(po);

    t1.join();
    t2.join();
    std::cout << x<<std::endl;
    return 0;
}