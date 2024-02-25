#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    int value;
    Node* next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node* top;
    int height;

public:
    Stack(int value)
    {
        Node* newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    ~Stack()
    {
        Node* temp = top;
        while(temp)
        {
            top = top->next;
            delete temp;
            temp = top;
        }
    }

    void printStack()
    {
        Node* temp = top;
        while(temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    Node* getTop()
    {
        return top;
    }

    int getHeight()
    {
        return height;
    }

    //add new node into stack
    void push(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    //pop top node of stack
    int pop()
    {
        if(height <= 0) return INT_MIN;
        Node* temp = top;
        top = top->next;
        int popValue = temp->value;
        delete temp;
        height--;
        
        return popValue;
    }

};
void sortStack(stack<int>& inputStack) {
    // Additional stack to temporarily store and sort elements
    stack<int> additionalStack;
 
    // Iterate until the input stack becomes empty
    while (!inputStack.empty()) {
        // Store the top element of the input stack in temp
        int temp = inputStack.top();
        inputStack.pop();
 
        // Move elements from additionalStack to inputStack while
        // they are greater than temp
        while (!additionalStack.empty() && additionalStack.top() > temp) {
            inputStack.push(additionalStack.top());
            additionalStack.pop();
        }
 
        // Push temp onto the additionalStack
        additionalStack.push(temp);
    }
 
    // Move sorted elements back to inputStack
    while (!additionalStack.empty()) {
        inputStack.push(additionalStack.top());
        additionalStack.pop();
    }
}

void mysortStack(stack<int>& inputStack) {
    stack<int> newStack;
    while(inputStack.empty() != true)
    {
        if(newStack.empty() == true)
        {
            newStack.push(inputStack.top());
            inputStack.pop();
        }

        else if(inputStack.top() > newStack.top())
        {
            // dua gia tro nho lui sau, dua gia tri lon hon vao inputStack.top()
            int temp = inputStack.top();
            inputStack.top() = newStack.top();
            inputStack.push(temp);
            newStack.pop();
        }
        else
        {
            newStack.push(inputStack.top());
            inputStack.pop();
        }
    }
    swap(inputStack, newStack);
    //return;
    //   +======================================================+
    //   |                 WRITE YOUR CODE HERE                 |
    //   | Description:                                         |
    //   | - This function sorts the input stack 'inputStack'.  |
    //   | - Uses an additional stack for sorting.              |
    //   | - Return type: void                                  |
    //   |                                                      |
    //   | Tips:                                                |
    //   | - Create an additional stack.                        |
    //   | - Pop elements from 'inputStack' and push them       |
    //   |   into 'additionalStack' in sorted order.            |
    //   | - Use a temporary variable to hold the top element   |
    //   |   of 'inputStack'.                                   |
    //   | - Move elements back to 'additionalStack' if needed. |
    //   | - Finally, move all elements back to 'inputStack'.   |
    //   | - Check output from Test.cpp in "User logs".         |
    //   +======================================================+
}
int main()
{
    //cout << INT_MIN <<endl;
    Stack st(4);
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    st.push(5);
    cout << st.getHeight() << endl;
    st.push(5);
    st.push(5);
    st.printStack();
    cout << st.getTop() << endl;
    cout << st.getHeight() << endl;


    return 0;
}