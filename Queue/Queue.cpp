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

class Queue
{
private:
    Node* first;
    Node* last;
    int length;
public:
    Queue(int value)
    {
        Node* newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }

    ~Queue()
    {
        Node* temp = first;
        while(first)
        {
            first = first->next;
            delete temp;
            temp = first;
        }
    }

    void printQueue()
    {
        Node* temp = first;
        while(temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    int getLength()
    {
        return length;
    }
    Node* getFirst()
    {
        return first;
    }
    Node* getLast()
    {
        return last;
    }

    void enqueue(int value)
    {
        Node* newNode = new Node(value);
        if(length == 0)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        length++;
        }
    };

int main()
{
    Queue myq(4);
    myq.printQueue();
    return 0;
}