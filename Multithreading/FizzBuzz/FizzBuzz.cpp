/*
A group of children sit in a circle, counting numbers out loud.
The first child says "one", the next child says "two", the next child says "three", and so on.
However, if the number is divisible by 3, they say "fizz" instead of the number. If the number
is divisible by 5, they say "buzz", and if the number is divisible by 3 and by 5, they say "fizzbuzz".
Write a function which produces the output from a game of Fizzbuzz:
*/
#include <iostream>
#include <thread>

using namespace std;

int players = 4;
string player_name[] = {"hrishi", "amy", "sandy", "sam"};
int max_number = 30;

void speak() 
{
    for (int i = 1; i <= max_number; i++) 
    {
        cout<<player_name[(i-1) % players] << " says ";
        if (i % 3 == 0 && i % 5 == 0)
        {
            cout<<" fizzbuzz"<<endl;
        }
        else if (i % 3 == 0) 
        {
            cout << "fizz"<<endl;

        }
        else if (i % 5 == 0) 
        {
            cout << "buzz"<<endl;
        }
        else 
        {
            cout << i <<endl;
        }
    }
}

int main()
{
    thread t1(speak);
    t1.join();
    return 0;
}

