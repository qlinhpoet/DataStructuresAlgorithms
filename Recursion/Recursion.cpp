#include <iostream>

using namespace std;
int x = 0;
void func3()
{
    x++;
    cout << 3 << endl;
}

void func2()
{
    func3();
    x++;
    cout << 2 << endl;
}

void func1()
{
    func2();
    x++;
    cout << 1 << endl;
}

int factorial(int n)
{
    if(n==1) return 1;
    return n*factorial(n-1);
}

int main()
{
    x = factorial(4);
    return 0;
}