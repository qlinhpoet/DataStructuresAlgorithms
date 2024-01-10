#include <iostream>

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

    void push(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

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