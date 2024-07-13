#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;

string a = "le quang linh";

void change(string* a)
{
    *a = "98"+*a;
}
bool subfc(char c)
{
        if(c == '1') return 1; else return 0;
}
int main()
{
    char c = 'a';
    cout << c << endl;
    char x = toupper(c);        //function in cctype lib
    cout << c << endl;
    cout << x;

    change(&a);
    cout <<a<<endl;
    //to convert character at position i to a numeric digit.
    a[0] = '3';
    cout << a[0] - '0';
    return 0;
}