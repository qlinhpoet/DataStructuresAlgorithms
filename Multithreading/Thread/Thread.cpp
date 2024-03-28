#include <iostream>
#include <thread>
using namespace std;

void hello()
{
    cout << "hello from thread with ID = " << std::this_thread::get_id() << endl;
}

void hello2()
{   
    //std::this_thread::sleep_for(2s);
    std::this_thread::sleep_for(std::chrono::seconds(2));   //wait 2s and run again.
    cout << "hello thread "<< endl;
}


int main()
{
    //Thread ID
    {
        cout << "main thread with ID = " << std::this_thread::get_id() << endl;

        std::thread thr(hello);

        cout<< "hello thread had ID = " << thr.get_id() << endl;
        thr.join();

        cout<< "hello thread had ID = " << thr.get_id() << endl;
    }

    //Pause thread
    {
        cout << "start thread" << endl;
        std::thread thr2(hello2);
        thr2.join();
    }

}