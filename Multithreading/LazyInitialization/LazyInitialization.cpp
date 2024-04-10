#include <mutex>
#include <thread>
#include <iostream>

class Test
{
public:
    Test()          {   }
    void func()     {   std::cout <<"hello\n";   };
};

Test *pTest = nullptr;
std::once_flag pTest_flag;
void process()
{
    //pass a callable object
    std::call_once(pTest_flag, []()
    {
        pTest = new Test;
    }
    );
    pTest->func();
}

//mayer singleton
void process2()
{
    static Test* pTest2 = new Test;   //cannot be interrupted.
    pTest2->func();
}

int main()
{
    std::thread thr1(process);
    std::thread thr2(process);
    thr1.join();
    thr2.join();
    return 0;
}