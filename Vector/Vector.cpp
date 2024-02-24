#include <iostream>
#include <vector>
#include <string>
using namespace std;

void removeElement(vector<int>& nums, int val)
{
    vector<int>::iterator it = nums.begin();
    while(nums.begin() != nums.end() && it != nums.end())
    {
        if(*it == val)
        {
            nums.erase(it);
            
        }
        else
        {
            it++;
        }
    }
}

vector<int> findMaxMin(vector<int>& myList)
{
    //donot have max min with empty string
    if(myList.size() == 0)
    {
        cout <<"error: empty string\n";
        while(1) ;
    }
    int max = myList[0];
    int min = max;
    for(vector<int>::iterator it = myList.begin(); it != myList.end(); it++)
    {
        if(*it > max) max = *it;
        else if(*it < min) min = *it;
    }
    vector<int> ret = {max, min};
    return ret;
}

string findLongestString(vector<string>& stringList)
{
    if(stringList.size() == 0) return "";
    string longestString = stringList[0];
    for(vector<string>::iterator it = stringList.begin(); it != stringList.end(); it++)
    {
        if(it->length() > longestString.length())
        {
            longestString = *it;
        }
    }
    return longestString;
}

void rotate(vector<int>& nums, int k)
{
    if(nums.size() <= 0) return;
    while(k>0)
    {
        int lastElement = nums.back();
        nums.pop_back();
        nums.insert(nums.begin(), lastElement);
        k--;
    }
}

int maxProfit(vector<int>& prices)
{
    int maxProfit = 0;
    int minValue = prices[0];
    
    for(vector<int>::iterator it = prices.begin(); it != prices.end(); it++)
    {
        if(minValue > *it)
        {
            minValue = *it;
        }
        else if(*it - minValue > maxProfit)
        {
            maxProfit = *it - minValue;
        }
    }
    return maxProfit;
    
}

int maxSubarray(vector<int>& nums) //O(n)
{
    if(nums.size() <= 0) return 0;
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        max_ending_here += *it;
        if(max_ending_here > max_so_far)
        {
            max_so_far = max_ending_here;
        }
        if(max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

int mymaxSubarray(vector<int>& nums)    //O(n^2)
{
    if(nums.size() <= 0) return 0;
    int maxSubarray = *nums.begin();
    
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        int maxSubarray2 = *it;
        int tempmax = maxSubarray2;
        for(vector<int>::iterator it2 = it+1; it2 != nums.end(); it2++)
        {
            tempmax = tempmax + *it2;
            if(tempmax > maxSubarray2)
            {
                maxSubarray2 = tempmax;
            }

        }
        if(maxSubarray2 > maxSubarray)
        {
            maxSubarray = maxSubarray2;
        }
    }
    return maxSubarray;

}
int removeDuplicates(vector<int>& nums)
{
    int length = 0;
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
}
void longestString();
void test();
void maxmin();
void printVector(const vector<int>& nums);
void rotatentime();
void maxsubarraytest();
int main()
{
    //vector<int> vtx = {1, 2, 3, 4, 5};
    //cout << maxSubarray(vtx);
    maxsubarraytest();
    return 0;
}
void printVector(const vector<string>& strings) {
    cout << "[ ";
    for (const auto& str : strings) {
        cout << "\"" << str << "\" ";
    }
    cout << "]";
}

void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

void test() {
    {
        cout << "\n----- Test: EmptyVector -----\n";
        vector<int> nums;
        cout << "Before: "; printVector(nums); cout << "\n";
        removeElement(nums, 10);
        cout << "After: "; printVector(nums); cout << "\n";
        cout << (nums.empty() ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: AllElementsAreTarget -----\n";
        vector<int> nums = {10};
        cout << "Before: "; printVector(nums); cout << "\n";
        removeElement(nums, 10);
        cout << "After: "; printVector(nums); cout << "\n";
        cout << (nums.empty() ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: NoTargetElement -----\n";
        vector<int> nums = {1, 2, 3, 4, 5};
        vector<int> original = nums;
        cout << "Before: "; printVector(nums); cout << "\n";
        removeElement(nums, 10);
        cout << "After: "; printVector(nums); cout << "\n";
        cout << (nums == original ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: MultipleTargetElementsInterspersed -----\n";
        vector<int> nums = {1, 10, 2, 10, 3, 10, 4, 10, 5};
        vector<int> expected = {1, 2, 3, 4, 5};
        cout << "Before: "; printVector(nums); cout << "\n";
        removeElement(nums, 10);
        cout << "After: "; printVector(nums); cout << "\n";
        cout << (nums == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: TargetElementsAtBeginning -----\n";
        vector<int> nums = {10, 10, 1, 2, 3};
        vector<int> expected = {1, 2, 3};
        cout << "Before: "; printVector(nums); cout << "\n";
        removeElement(nums, 10);
        cout << "After: "; printVector(nums); cout << "\n";
        cout << (nums == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: TargetElementsAtEnd -----\n";
        vector<int> nums = {1, 2, 3, 10, 10};
        vector<int> expected = {1, 2, 3};
        cout << "Before: "; printVector(nums); cout << "\n";
        removeElement(nums, 10);
        cout << "After: "; printVector(nums); cout << "\n";
        cout << (nums == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: SingleTargetElement -----\n";
        vector<int> nums = {1, 2, 3, 10, 4, 5};
        vector<int> expected = {1, 2, 3, 4, 5};
        cout << "Before: "; printVector(nums); cout << "\n";
        removeElement(nums, 10);
        cout << "After: "; printVector(nums); cout << "\n";
        cout << (nums == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: SingleElementTarget -----\n";
        vector<int> nums = {10};
        cout << "Before: "; printVector(nums); cout << "\n";
        removeElement(nums, 10);
        cout << "After: "; printVector(nums); cout << "\n";
        cout << (nums.empty() ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: SingleElementNotTarget -----\n";
        vector<int> nums = {1};
        vector<int> original = nums;
        cout << "Before: "; printVector(nums); cout << "\n";
        removeElement(nums, 10);
        cout << "After: "; printVector(nums); cout << "\n";
        cout << (nums == original ? "PASS\n" : "FAIL\n");
    }
}

void maxmin() {
    {
        cout << "\n----- Test: SingleElement -----\n";
        vector<int> nums = {5};
        vector<int> result = findMaxMin(nums);
        vector<int> expected = {5, 5};
        cout << "Input: "; printVector(nums); cout << "\n";
        cout << "Output: "; printVector(result); cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: AscendingOrder -----\n";
        vector<int> nums = {1, 2, 3, 4, 5};
        vector<int> result = findMaxMin(nums);
        vector<int> expected = {5, 1};
        cout << "Input: "; printVector(nums); cout << "\n";
        cout << "Output: "; printVector(result); cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: DescendingOrder -----\n";
        vector<int> nums = {5, 4, 3, 2, 1};
        vector<int> result = findMaxMin(nums);
        vector<int> expected = {5, 1};
        cout << "Input: "; printVector(nums); cout << "\n";
        cout << "Output: "; printVector(result); cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: RandomOrder -----\n";
        vector<int> nums = {3, 5, 1, 4, 2};
        vector<int> result = findMaxMin(nums);
        vector<int> expected = {5, 1};
        cout << "Input: "; printVector(nums); cout << "\n";
        cout << "Output: "; printVector(result); cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: AllSameElements -----\n";
        vector<int> nums = {3, 3, 3, 3, 3};
        vector<int> result = findMaxMin(nums);
        vector<int> expected = {3, 3};
        cout << "Input: "; printVector(nums); cout << "\n";
        cout << "Output: "; printVector(result); cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: PositiveAndNegative -----\n";
        vector<int> nums = {-3, 5, -1, 4, 2};
        vector<int> result = findMaxMin(nums);
        vector<int> expected = {5, -3};
        cout << "Input: "; printVector(nums); cout << "\n";
        cout << "Output: "; printVector(result); cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: OnlyNegative -----\n";
        vector<int> nums = {-3, -5, -1, -4, -2};
        vector<int> result = findMaxMin(nums);
        vector<int> expected = {-1, -5};
        cout << "Input: "; printVector(nums); cout << "\n";
        cout << "Output: "; printVector(result); cout << "\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }
}

void longestString() {
    {
        cout << "\n----- Test: SingleString -----\n";
        vector<string> stringList = {"apple"};
        string result = findLongestString(stringList);
        string expected = "apple";
        cout << "Input: "; printVector(stringList); cout << "\n";
        cout << "Output: \"" << result << "\"\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: FirstStringIsLongest -----\n";
        vector<string> stringList = {"watermelon", "apple", "banana"};
        string result = findLongestString(stringList);
        string expected = "watermelon";
        cout << "Input: "; printVector(stringList); cout << "\n";
        cout << "Output: \"" << result << "\"\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: LastStringIsLongest -----\n";
        vector<string> stringList = {"apple", "banana", "watermelon"};
        string result = findLongestString(stringList);
        string expected = "watermelon";
        cout << "Input: "; printVector(stringList); cout << "\n";
        cout << "Output: \"" << result << "\"\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: MiddleStringIsLongest -----\n";
        vector<string> stringList = {"apple", "watermelon", "banana"};
        string result = findLongestString(stringList);
        string expected = "watermelon";
        cout << "Input: "; printVector(stringList); cout << "\n";
        cout << "Output: \"" << result << "\"\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: AllStringsSameLength -----\n";
        vector<string> stringList = {"apple", "melon", "fruit"};
        string result = findLongestString(stringList);
        string expected = "apple"; // since "apple" is the first string of that length
        cout << "Input: "; printVector(stringList); cout << "\n";
        cout << "Output: \"" << result << "\"\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: EmptyList -----\n";
        vector<string> stringList = {};
        string result = findLongestString(stringList);
        string expected = "";
        cout << "Input: "; printVector(stringList); cout << "\n";
        cout << "Output: \"" << result << "\"\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: SomeEmptyStrings -----\n";
        vector<string> stringList = {"apple", "", "banana", ""};
        string result = findLongestString(stringList);
        string expected = "banana";
        cout << "Input: "; printVector(stringList); cout << "\n";
        cout << "Output: \"" << result << "\"\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }

    {
        cout << "\n----- Test: DifferentCharacterStrings -----\n";
        vector<string> stringList = {"12345", "b@n@n@", "apple!"};
        string result = findLongestString(stringList);
        string expected = "b@n@n@";
        cout << "Input: "; printVector(stringList); cout << "\n";
        cout << "Output: \"" << result << "\"\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
    }
}


void rotatentime() {
    // BasicTestCases
    {
        cout << "\n----- Basic Test Cases -----\n";

        vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
        rotate(nums1, 2);
        cout << "EXPECTED: [6, 7, 1, 2, 3, 4, 5], RETURNED: ";
        printVector(nums1);
        cout << "\n";

        vector<int> nums2 = {1, 2, 3, 4, 5};
        rotate(nums2, 7);
        cout << "EXPECTED: [4, 5, 1, 2, 3], RETURNED: ";
        printVector(nums2);
        cout << "\n";

        vector<int> nums3 = {1, 2, 3};
        rotate(nums3, 0);
        cout << "EXPECTED: [1, 2, 3], RETURNED: ";
        printVector(nums3);
        cout << "\n";

        vector<int> nums4 = {1, 2, 3, 4, 5};
        rotate(nums4, 5);
        cout << "EXPECTED: [1, 2, 3, 4, 5], RETURNED: ";
        printVector(nums4);
        cout << "\n";
    }

    // EdgeCases
    {
        cout << "\n----- Edge Cases -----\n";

        vector<int> nums1;
        rotate(nums1, 4);
        cout << "EXPECTED: [], RETURNED: ";
        printVector(nums1);
        cout << "\n";

        vector<int> nums2 = {1};
        rotate(nums2, 3);
        cout << "EXPECTED: [1], RETURNED: ";
        printVector(nums2);
        cout << "\n";
    }

    // LargeTestCases
    {
        cout << "\n----- Large Test Cases -----\n";

        vector<int> nums(100000, 5);  // 100,000 entries all with the value 5
        nums[50000] = 10;
        rotate(nums, 50001);
        cout << "After rotation, first element: " << nums[0] << ", second element: " << nums[1] << "\n";
    }
}

void maxsubarraytest() {
    // PositiveNumbersOnly
    {
        vector<int> nums = {1, 2, 3, 4, 5};
        int returnedResult = maxSubarray(nums);
        cout << "\n----- Positive Numbers Only -----\n";
        cout << "Input Vector: "; printVector(nums); cout << "\n";
        cout << "EXPECTED: 15, RETURNED: " << returnedResult << "\n";
    }

    // NegativeNumbersOnly
    {
        vector<int> nums = {-1, -2, -3, -4, -5};
        int returnedResult = maxSubarray(nums);
        cout << "\n----- Negative Numbers Only -----\n";
        cout << "Input Vector: "; printVector(nums); cout << "\n";
        cout << "EXPECTED: -1, RETURNED: " << returnedResult << "\n";
    }

    // MixOfPositiveAndNegativeNumbers
    {
        vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int returnedResult = maxSubarray(nums);
        cout << "\n----- Mix of Positive and Negative Numbers -----\n";
        cout << "Input Vector: "; printVector(nums); cout << "\n";
        cout << "EXPECTED: 6, RETURNED: " << returnedResult << "\n";
    }

    // SingleElement
    {
        vector<int> nums = {4};
        int returnedResult = maxSubarray(nums);
        cout << "\n----- Single Element -----\n";
        cout << "Input Vector: "; printVector(nums); cout << "\n";
        cout << "EXPECTED: 4, RETURNED: " << returnedResult << "\n";
    }

    // EmptyList
    {
        vector<int> nums = {};
        int returnedResult = maxSubarray(nums);
        cout << "\n----- Empty List -----\n";
        cout << "Input Vector: "; printVector(nums); cout << "\n";
        cout << "EXPECTED: 0, RETURNED: " << returnedResult << "\n";
    }
}


