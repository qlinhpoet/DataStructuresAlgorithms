#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        int countDup = 0;
        int ret = length;
        for(int i=0; i<length; i++)
        {
                if(i+1 < ret && nums[i] == nums[i+1])
                {
                    countDup++;
                    if(countDup >= 2)
                    {
                        ret--;
                        for(int k=i+1; k<length; k++)
                        {
                            nums[k-1] = nums[k];
                        }
                        i--;
                    }

                }
                else countDup = 0;
        }
        return ret;
    }

vector<int> nums = {0,0,1,1,1,1,2,3,3};
int main()
{
    cout <<"hello";
    cout << removeDuplicates(nums);
    cout <<"hello";
    return 0;
}

