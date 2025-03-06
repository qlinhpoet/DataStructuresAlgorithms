#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm> 
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

int majorityElement1(vector<int>& nums) {
    unordered_map<int, int> myMap;
    for(int i=0; i<nums.size(); i++)
    {
        if(myMap.find(nums[i]) == myMap.end())
        {
            myMap[nums[i]] = 1;
        }
         else myMap[nums[i]]++;
        if(myMap[nums[i]] > nums.size()/2) return nums[i];
    }
    return 0;
}

int majorityElement(vector<int>& nums) 
{
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
}
vector<int> nums = {3,2,3};
int main()
{
    cout << majorityElement(nums);

    return 0;
}
