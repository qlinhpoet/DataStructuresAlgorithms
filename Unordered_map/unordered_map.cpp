#include <iostream>
#include <unordered_map>

using namespace std;

string str = "geeksforgeeks";

void frequencyStr(string str)
{
    //creat a hash table : key - frequency
    unordered_map<char, int> M;
    for(char c:str)
    {
        //method find(key) return iterator to the element
        //if find(key) == iterator end()=> key not exist in unordered_map
        if(M.find(c) == M.end())
        {
            // inserting values by using [] operator
            M[c] = 1;
        }
        else
        {
            //update value
            M[c]++;
        }
    }
    //traverse the map
    for (auto& it : M) {
        cout << it.first << ' ' << it.second << '\n';
    }

}

int main()
{
    frequencyStr(str);
    unordered_map<char, int> mm;
    cout << mm['x'];

    return 0;
}
