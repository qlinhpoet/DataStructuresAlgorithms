#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = nullptr;

    }
};

class LinkedList
{
private:
    Node* head;
    Node *tail;
    int length;
public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while(head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    Node* getHead()
    {
        return head;
    }

    Node* getTail()
    {
        return tail;
    }

    int getLength()
    {
        return length;
    }

    void printList()
    {
        Node * temp = head;
        while(temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

};

void checkTestResult(bool condition)
{
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main()
{

    // Test 1: InitializesHeadCorrectly
    {
        cout << "\n------ LinkedList Test: InitializesHeadCorrectly ------\n";

        LinkedList ll(5);

        cout << "Expected Head Value: 5\n";
        cout << "Actual Head Value: " << ll.getHead()->value << "\n";

        checkTestResult(ll.getHead()->value == 5);
    }

    // Test 2: InitializesTailCorrectly
    {
        cout << "\n------ LinkedList Test: InitializesTailCorrectly ------\n";

        LinkedList ll(5);

        cout << "Expected Tail Value: 5\n";
        cout << "Actual Tail Value: " << ll.getTail()->value << "\n";

        checkTestResult(ll.getTail()->value == 5);
    }

    // Test 3: InitializesLengthCorrectly
    {
        cout << "\n------ LinkedList Test: InitializesLengthCorrectly ------\n";

        LinkedList ll(5);

        cout << "Expected Length: 1\n";
        cout << "Actual Length: " << ll.getLength() << "\n";

        checkTestResult(ll.getLength() == 1);
    }

    // Test 4: HeadAndTailAreTheSameNode
    {
        cout << "\n------ LinkedList Test: HeadAndTailAreTheSameNode ------\n";

        LinkedList ll(5);

        cout << "Checking if head and tail point to the same node...\n";

        checkTestResult(ll.getHead() == ll.getTail());
    }
    return 0;
}
