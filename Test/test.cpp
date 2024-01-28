#include <iostream>

using namespace std;

int countNumber1(int value)
{
    
    int count = 0;
    unsigned int posValue = (unsigned int)value;

    while(posValue != 0)
    {
        if((posValue & (int)0x01) == 1)
        {
            count++;
        }
        posValue = posValue >> 1;
    }
    return count;
}

int main()
{
    int x = -79;
    cout << countNumber1(x);
    return 0;
}