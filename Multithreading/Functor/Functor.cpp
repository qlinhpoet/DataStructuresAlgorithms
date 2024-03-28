//function object - functor
#include <iostream>
using namespace std;

class testFunctor
{
public:
    //functor
    void operator()(int i)      {   return i;   }
    int operator()(int a, int b){   return a+b; }
};

int main()
{
    testFunctor ob1;
    
    ob1.operator()(3,5);    //original way
    
    ob1(3,5);               //short way - expected of functor

    return 0;
}