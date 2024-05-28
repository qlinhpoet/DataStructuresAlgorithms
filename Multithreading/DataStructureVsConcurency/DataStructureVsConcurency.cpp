#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::vector<int> vec;       //shared vector

std::mutex mut;

void func1()
{
    std::lock_guard<std::mutex> lgd(mut);
    for(int i=0; i<1000; i++)
    {
        vec.push_back(i);
    }
}

void func2()
{
    std::lock_guard<std::mutex> lgd(mut);
    for(int i=1000; i<2000; i++)
    {
        vec.push_back(i);
    }
} 

int main()
{
    std::thread thr1(func1);
    std::thread thr2(func2);

    thr1.join();
    thr2.join();

	std::cout << "shptr data: ";
	for (int i = 0; i < 2000; ++i)
		std::cout << vec[i] << ", ";

	std::cout << "Finished\n";


}