#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
#include <future>
#include <string>

class Bank
{
private:
    //shared data
public:
    //take money out of account
    void debit(const std::string &name, int amount)
    {
        std::cout <<"debit amount " << amount <<" from" << name <<std::endl; 
    }

    //
    void credit(const std::string &name, int amount)
    {
        std::cout<< "credit amount " <<amount << " to " << name <<std::endl;
    }

    void print(const std::string &name)
    {
        std::cout <<"display account " << name << std::endl;
    }
};

//Monitor class, can wrap any type
template <typename T>
class Monitor
{
    T data;             //the object to be monitored
    std::mutex mut;     //mutex to protect object
public:
    //Default constructor
    Monitor<T>(T data = T{}): data(data){};

    //funtor
    template <typename Func>
    auto operator() (Func func)
    {
        std::lock_guard<std::mutex> lck(mut);
        return func(data);
    }

};

int main()
{

    Monitor<Bank> mon;      //monitor wrapper for bank class

    //operator() is called, lamda expression is passed to operator()
    //mut is locked first and then, lamda expression is called.
    mon([](Bank bank)       
    {
        bank.debit("Linh", 1000);
        bank.credit("Nhu", 1000);
        bank.print("Linh");
        bank.print("Nhu");
    });


    return 0;
}