#include <iostream>
#include <stack>
#include <string>
class Solution {
public:
    bool isPalindrome1(int x) {
        if(x<0) return false;
        if(x == 0) return true;
        std::stack<int> test;
        int temp = x;
        while(temp > 0)
        {
            test.push(temp % 10);
            temp = temp / 10;
        }
        while(test.empty() == false)
        {
            if(test.top() == (x % 10))
            {
                x = x/10;
                test.pop();
            }
            else
            return false;
        }
        return true;
    }
    bool isPalindrome2(int x) {

        if(x<0) return false;
        if(x == 0) return true;
        int temp1 = x;
        int temp2 = 0;
        while(temp1 > 0)
        {
            temp2 = temp2*10 + temp1%10;
            temp1 = temp1 / 10;
        }
        std::cout <<temp2<<std::endl;
        if(temp2 == x) return true;
        else return false;
    }
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        std::string old = std::to_string(x);
        for (int i = 0; i < old.length() / 2; i++) {
            if (old.at(i) != old.at(old.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s1;
    std::cout << s1.isPalindrome(112211);
    return 0;
}