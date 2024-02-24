#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int maxProfit = 0;
    
}

void printVector(const vector<int>& nums, int newSize = -1) {
    cout << "[";
    int sizeToPrint = (newSize == -1) ? nums.size() : newSize;
    for (int i = 0; i < sizeToPrint; i++) {
        cout << nums[i];
        if (i < sizeToPrint - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

int myremoveDuplicates(vector<int>& nums)
{
    vector<int>::iterator current = nums.begin();
    for(size_t i = 1; i<nums.size(); i++)
    {
        if(*current == *(current + 1))
        {
            nums.erase(current+1);
            i--;

        }
        else
        {
            current++;
        }
    }
    return nums.size();
}
int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
 
    int writePointer = 1;
 
    for (int readPointer = 1; readPointer < nums.size(); readPointer++) {
        if (nums[readPointer] != nums[readPointer - 1]) {
            nums[writePointer] = nums[readPointer];
            writePointer++;
        }
    }
 
    return writePointer;
}

int main() {
    {
        cout << "\n----- Test: EmptyList -----\n";
        vector<int> nums = {};
        cout << "Before: "; printVector(nums); cout << "\n";
        int newSize = removeDuplicates(nums);
        cout << "After: "; printVector(nums, newSize); cout << "\n";
        cout << (newSize == 0 && nums.empty() ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: SingleElement -----\n";
        vector<int> nums = {5};
        cout << "Before: "; printVector(nums); cout << "\n";
        int newSize = removeDuplicates(nums);
        cout << "After: "; printVector(nums, newSize); cout << "\n";
        cout << (newSize == 1 && nums[0] == 5 ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: MultipleDuplicates -----\n";
        vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 4, 4};
        cout << "Before: "; printVector(nums); cout << "\n";
        int newSize = removeDuplicates(nums);
        cout << "After: "; printVector(nums, newSize); cout << "\n";
        if (newSize == 4 && nums[0] == 1 && nums[1] == 2 && nums[2] == 3 && nums[3] == 4) {
            cout << "PASS\n";
        } else {
            cout << "FAIL\n";
        }
    }

    {
        cout << "\n----- Test: NoDuplicates -----\n";
        vector<int> nums = {1, 2, 3, 4, 5};
        cout << "Before: "; printVector(nums); cout << "\n";
        int newSize = removeDuplicates(nums);
        cout << "After: "; printVector(nums, newSize); cout << "\n";
        bool pass = true;
        if (newSize != 5) {
            pass = false;
        } else {
            for (int i = 0; i < newSize; i++) {
                if (nums[i] != i + 1) {
                    pass = false;
                    break;
                }
            }
        }
        cout << (pass ? "PASS\n" : "FAIL\n");
    }
    return 0;
}


