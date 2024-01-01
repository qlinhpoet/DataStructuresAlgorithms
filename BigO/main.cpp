#include <iostream>

using namespace std;

void PrinItems(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << i << j << endl;
        }
    }

}

int main()
{
    PrinItems(10);
    return 0;
}
