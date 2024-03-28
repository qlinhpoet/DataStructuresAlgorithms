#include <iostream>

void func(int& test);       //called when pass lvalue
void func(int&& test);      //called when pass rvalue

void overload(int& test)
{
    test++;
}

void overload(int&& test)
{
    test++;
}

void func(int&& x)
{
    std::cout << x << std::endl;
}

int main()
{
    //func(5);

    //int y = 10;
    //func(y);          //error: y is a lvalue
    //func(std::move(y)); //std::move() cast y to rvalue
    
    int value=123;
    std::cout << value << std::endl;
    overload(value);
    std::cout << value << std::endl;
    overload(std::move(value));
    std::cout << value << std::endl;
}