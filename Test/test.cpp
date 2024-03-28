#include <iostream>
#include <thread>

using namespace std;

//callable object - thread entry point
void hello()
{
    cout << "hello world\n";
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

string str = "abc";
int value3 = 5;
int main()
{
    //creat new std::thread object
    //pass the task function to constructor
    std::thread thr(hello);
    
    //wait for thread complete
    thr.join();

    //pass by value
    std::thread thr2(hello2, str);
    thr2.join();

    //pass by move - after excute, std is empty
    std::thread thr3(hello3, std::move(str));
    thr3.join();
    cout << str << endl;
    str = "abc";
    //pass by move - after excute, std is empty
    std::thread thr4(hello4, std::ref(str));
    thr4.join();
    cout << str << endl;
}
