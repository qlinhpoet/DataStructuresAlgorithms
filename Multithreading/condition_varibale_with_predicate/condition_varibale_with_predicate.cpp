#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <string>
#include <chrono>
std::condition_variable cond_var;
std::mutex mut;
//predicate
bool doneWait = false;
std::string sData = "initial";
void reader()
{
    //lock mutex but still call unlock
    std::unique_lock<std::mutex> uniq_lck(mut);

    cond_var.wait(uniq_lck, []{return doneWait;});

    std::cout <<"sData: " << sData <<std::endl;

	doneWait = false;
}
void writer()
{
    //lock_guard: lock mutex until destroy
    std::lock_guard<std::mutex> lck_guard(mut);
    sData = "populated";
    std::cout<<"updated\n";
	doneWait = true;
    cond_var.notify_one();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	doneWait = true;
	
}

int main()
{
    std::cout <<"initial sData: " << sData <<std::endl;
    std::thread thr1(reader);
    //problem happen if writer call notify_one before reader call wait
    std::thread thr2(writer);
    thr1.join();
    thr2.join();

    return 0;
}