#include <iostream>


int main()
{
    try
    {
            int x = 10;
            throw x;
            std::cout <<"this line not excute";     //not excuted
    }
    catch(const int x)
    {
            std::cout << x << "\n";
            std::cout <<"this line is excuted\n";
    }
    catch(char x)
    {
            std::cout <<"gan nhat\n";
    }
    try
    {
        char a = 'a';
        throw a;
        try
        {
            int x = 10;
            throw x;
            std::cout <<"this line not excute";     //not excuted
        }
        catch(const int x)
        {
            std::cout << x << "\n";
            std::cout <<"this line is excuted\n";
        }
        catch(char x)
        {
            std::cout <<"gan nhat\n";
        }
    }
    catch(char x)
    {
        std::cout << x << "\n";
    }
    std::cout <<"this line is excuted";
    
    return 0;
}