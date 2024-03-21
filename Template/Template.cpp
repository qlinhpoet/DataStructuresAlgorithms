#include <iostream>

using namespace std;

//function template
//template<typename T1, typename T2>
template<class T1, class T2>
//template< class T3>
T2 mySum(T1 v1, T2 v2)
{
    return (v1 + v2);
}




int main()
{
    cout << mySum(3,5) << endl;
    cout << mySum<int, float>(3, 4.5);
    return 0;
}

