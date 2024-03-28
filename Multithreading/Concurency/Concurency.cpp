#include <iostream>
#include <thread>

using namespace std;

//callable object - thread entry point
void hello()
{
    //cout << "hello world\n";
}

void hello2(string x)
{
    cout << x << endl;
}

//pass by move
void hello3(string&& x)
{
    cout << x << endl;
}

void hello4(string& x)
{
    cout << x << endl;
}

class greeter
{
    public:
    void hello(){ std::cout << "member function \n";}      //member function
};

//creat an object of class
greeter greet;

string str = "abc";
int value3 = 5;
int main()
{
    //creat new std::thread object
    //pass the task function to constructor
    std::thread thr(hello);

    cout <<"hello thread has native handle " << thr.native_handle() <<endl;     //thr.native_handle() != 0
    
    //wait for thread complete
    thr.join();
    cout <<"hello thread has native handle " << thr.native_handle() << endl;    //thr.native_handle() = 0

    //pass by value
    std::thread thr2(hello2, "hello x");
    thr2.join();

    //pass by move
    std::thread thr3(hello3, std::move(str));
    thr3.join();

    cout << str << endl;            //str is empty after pass by move
    str = "xyz";

    //pass by reference
    std::thread thr4(hello4, std::ref(str));
    thr4.join();

    //pass pointer to member function and pointer to object.
    //std::thread thr5(&greet.hello, &greet);       or
    std::thread thr5(&greeter::hello, &greet);
    thr5.join();
}
