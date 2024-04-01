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

//func with 1 argument is std::thread object
void func(std::thread thr)
{
    thr.join();
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
    cout << "\n\n//pause thread\n";
    {
        cout << "start thread" << endl;
        std::thread thr2(hello2);           //pause thread 2s
        thr2.join();
    }

    //pass std::thread object as function argument
    cout << "\n\n//pass std::thread object as function argument\n";
    {
        //creat a thread name thr
        std::thread thr(hello);

        //pass object thr using std::move
        func(std::move(thr));

        //pass a temporary object
        func(std::thread(hello));

    }

}