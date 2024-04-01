#include <iostream>
#include <thread>

using namespace std;

void hello(int i)
{
    //add delay to avoid data race.
    std::this_thread::sleep_for(std::chrono::seconds(i));
    cout << "hello thread " << i <<"\n";
}
int main()
{
    //create and start 3 thread
    std::thread thr1(hello, 1);
    std::thread thr2(hello, 2);
    std::thread thr3(hello, 3);

    //wait for them finish
    thr1.join();
    thr2.join();
    thr3.join();

    return 0;
}