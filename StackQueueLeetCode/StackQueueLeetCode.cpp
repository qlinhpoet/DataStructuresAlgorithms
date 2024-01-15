#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StackVector {
    private:
        vector<int> stackVector;
    
    public:
        vector<int>& getStackVector() {
            return stackVector;
        }
    
        void printStack() {
            for (int i = stackVector.size() - 1; i >= 0; i--) {
                cout << stackVector[i] << endl;
            }
        }
    
        bool isEmpty() {
            return stackVector.size() == 0;
        }
    
        int peek() {
            if (isEmpty()) {
                return int();
            } else {
                return stackVector[stackVector.size() - 1];
            }
        }
    
        int size() {
            return stackVector.size();
        }
    
        void push(int value) {
            stackVector.push_back(value);
        }
        
        void pop()
        {
            if(stackVector.size() > 0)
            {
                stackVector.pop_back();
            }
        }
};

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
}

