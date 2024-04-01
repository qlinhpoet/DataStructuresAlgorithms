#include <thread>
#include <iostream>

void hello()
{
    try
    {
        throw std::exception();
        std::cout <<"linh\n";       //khong duoc called
    }
    catch (std::exception& e)
    {
        std::cout << "exception caught: " << e.what() << std::endl;
    }
}

void noHandle()
{
    throw std::exception();

    std::cout << "next line\n";
}

void hello3()
{

}

int main()
{
    std::thread thr(hello);
    thr.join();

    std::cout <<"\n\nin case no suitable handle => program terminated\n";
    try
    {
        //std::thread thr2(noHandle);
        //thr2.join();
    }
    catch(std::exception& e)
    {
        std::cout << "exception caught: " << e.what() << std::endl;
    }

    std::cout <<"\n\nin case thread no join()\n";
    std::thread thr3(hello3);
    try
    {
        throw std::exception();
        std::cout <<"linh\n";       //khong duoc called
    }
    catch (std::exception& e)
    {
        std::cout << "exception caught: " << e.what() << std::endl;
    }
    thr3.join();

    std::cout << "finish\n";
}