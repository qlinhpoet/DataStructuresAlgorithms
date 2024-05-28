#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
 
// Function to print vector
void printVector(vector<int> v)
{
    // lambda expression to print vector
    for_each(v.begin(), v.end(), [](int i)
    {
        std::cout << i << " ";
    });
    cout << endl;
}
 
//int main()
//{
    // vector<int> v {4, 1, 3, 5, 2, 3, 1, 7};
 
    // printVector(v);
 
    // // below snippet find first number greater than 4
    // // find_if searches for an element for which
    // // function(third argument) returns true
    // vector<int>:: iterator p = find_if(v.begin(), v.end(), [](int i)
    // {
    //     return i > 4;
    // });
    // cout << "First number greater than 4 is : " << *p << endl;
 
 
    // //     We can also access function by storing this into variable
    // auto square = [](int i)
    // {
    //     return i * i;
    // };

    // cout << "Square of 5 is : " << square(5) << endl;

    // vector<int> vec = { 10, 20, 30, 40, 50 }; 
  
    // // Capture vector values by value using capture clauses 
    // auto lambda = [vec]() { 
    //     cout 
    //         << "Vector values inside the lambda function: "; 
    //     for (int num : vec) { 
    //         num *= 10; // Make changes in the captured 
    //                    // vector values 
    //         cout << num << " "; 
    //     } 
    //     cout << endl; 
    // }; 
    // return 0;
//}

int main() 
{ 
    int n = 2;
    //capture by calue
    auto capbyvalue = [n]() {};

    std::cout <<"n truoc khi vao lamda:" <<n<<std::endl;
    //capture by reference
    auto capbyreference = [&n](int x)
    {
        return ++n;
    };
    capbyreference(2);
    std::cout<<"n sau khi cap by reference lambda:" << n << std::endl;

    return 0; 
}