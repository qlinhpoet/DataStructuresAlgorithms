#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char c = 'a';
    cout << c << endl;
    char x = toupper(c);        //function in cctype lib
    cout << c << endl;
    cout << x;
    return 0;
}