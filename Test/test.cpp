#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string reverseString(const string& str) 
{
    stack<char> stackStr;
    for(int i=0; i<str.length(); i++)
    {
        stackStr.push(str[i]);
    }
    string reverseStr = "";
    for(int i=0; i<str.length(); i++)
    {
        reverseStr += stackStr.top();
        stackStr.pop();
    }
    cout << reverseStr;
    return reverseStr;

}

bool isBalancedParentheses(const string& parentheses) 
{
    stack<char> charStack;
    for(char c : parentheses)
    {
        if('(' == c)
        {
            charStack.push(c);
        }
        if(')' == c )
        {
            if (!charStack.empty() && charStack.top() == '(')
            charStack.pop();
            else return false;
        }   
    }
    if(!charStack.empty())
    {
        return false;
    }
    return true;
}
const string str = "(a)";
int main()
{
    if(isBalancedParentheses(str) == true)
    {
        cout <<"true";
    }
    else
    {
        cout<< "false";
    }
    // cout << "\n----- Test: Unbalanced Closing Parentheses -----\n";
    // {
    //     string inputs[] = {")", "())", "(()))"};
    //     for (const string &input : inputs) {
    //         cout << "Input: \"" << input << "\"\n";
    //         cout << "Output: " << (isBalancedParentheses(input) ? "Balanced" : "Unbalanced") << " - EXPECTED: Unbalanced\n";
    //         cout << (!isBalancedParentheses(input) ? "PASS\n" : "FAIL\n");
    //     }
    // }

    // cout << "\n----- Test: Mixed Parentheses -----\n";
    // {
    //     string balancedInput = "()()";
    //     string unbalancedInputs[] = {"()(", "())()"};

    //     cout << "Input: \"" << balancedInput << "\"\n";
    //     cout << "Output: " << (isBalancedParentheses(balancedInput) ? "Balanced" : "Unbalanced") << " - EXPECTED: Balanced\n";
    //     cout << (isBalancedParentheses(balancedInput) ? "PASS\n" : "FAIL\n");

    //     for (const string &input : unbalancedInputs) {
    //         cout << "Input: \"" << input << "\"\n";
    //         cout << "Output: " << (isBalancedParentheses(input) ? "Balanced" : "Unbalanced") << " - EXPECTED: Unbalanced\n";
    //         cout << (!isBalancedParentheses(input) ? "PASS\n" : "FAIL\n");
    //     }
    // }

}

