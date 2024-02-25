#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> findDuplicates(const vector<int>& nums) {
    vector<int> duplicateVector;
    
    for(int i = 0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            if(nums[i] == nums[j])
            {
                duplicateVector.push_back(nums[i]);
            }
        }
    }
    return duplicateVector;
	//   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function finds duplicate integers in a given |
	//   |   vector.                                           |
	//   | - It uses an unordered_map to count each integer's  |
	//   |   occurrences.                                      |
	//   | - Loops through the map to find duplicates.         |
	//   |                                                     |
	//   | Return type: vector<int>                            |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'numCounts' keeps track of each integer's count.  |
	//   | - 'duplicates' stores duplicate integers found.     |
	//   | - Check output from Test.cpp in "User logs".        |
	//   +=====================================================+
}
int main() {
    auto printVector = [](const vector<int>& v) {
        cout << "(";
        for(int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) cout << ", ";
        }
        cout << ")";
    };

    {
        cout << "\n----- Test: No Duplicates -----\n";
        vector<int> nums = {1, 2, 3, 4, 5};
        vector<int> expected = {};
        vector<int> result = findDuplicates(nums);
        cout << "EXPECTED: No Duplicates\n";
        cout << "RETURNED: ";
        printVector(result);
        cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Some Duplicates -----\n";
        vector<int> nums = {1, 2, 3, 2, 1, 4, 5, 6, 5, 2};
        vector<int> expected = {1, 2, 5};
        vector<int> result = findDuplicates(nums);
        sort(result.begin(), result.end());
        cout << "EXPECTED: Has Duplicates: ";
        printVector(expected);
        cout << "\n";
        cout << "RETURNED: ";
        printVector(result);
        cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: All Duplicates -----\n";
        vector<int> nums = {1, 1, 2, 2, 3, 3};
        vector<int> expected = {1, 2, 3};
        vector<int> result = findDuplicates(nums);
        sort(result.begin(), result.end());
        cout << "EXPECTED: Has Duplicates: (1, 2, 3)\n";
        cout << "RETURNED: ";
        printVector(result);
        cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: Empty Vector -----\n";
        vector<int> nums = {};
        vector<int> expected = {};
        vector<int> result = findDuplicates(nums);
        cout << "EXPECTED: No Duplicates\n";
        cout << "RETURNED: ";
        printVector(result);
        cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }
    return 0;
}



/* 
    EXPECTED OUTPUT:
    ----- Test: No Duplicates -----
    EXPECTED: No Duplicates
    RETURNED: ()
    PASS
    ----- Test: Some Duplicates -----
    EXPECTED: Has Duplicates: (1, 2, 5)
    RETURNED: (1, 2, 5)
    PASS
    ----- Test: All Duplicates -----
    EXPECTED: Has Duplicates: (1, 2, 3)
    RETURNED: (1, 2, 3)
    PASS
    ----- Test: Empty Vector -----
    EXPECTED: No Duplicates
    RETURNED: ()
    PASS

*/

