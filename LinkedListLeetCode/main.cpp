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

class LinkedList
{
private:
    Node* head;
    Node* tail;
public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;

    }

    ~LinkedList()
    {
        Node* temp = head;
        while(temp)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        Node* temp = head;
        while(temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void makeEmpty()
    {
        Node* temp=head;
        while(temp)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    Node* Get(int pos, int length)
    {
        if(pos < 0 || pos >= length)
        {
            return nullptr;
        }
        Node* temp = head;
        for(int i=0; i<pos; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    Node* myfindMiddleNode()
    {
        int length = 0;
        int mid = 0;
        Node* temp = head;

        while(temp)
        {
            length++;
            temp = temp->next;
        }

        if(length % 2 == 0)
        {
            mid = (length / 2);
        }
        else
        {
            mid = (length -  1) / 2;
        }
        temp = head;
        for(int i=0; i<mid; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    Node* findMiddleNode()
    {
        Node* temp1 = head;
        Node* temp2 = head;

        while( temp2 != nullptr && temp2->next != nullptr )
        {
            temp1 = temp1->next;
            temp2 = temp2->next->next;
        }

        return temp1;
    }

    Node* getHead()
    {
        return head;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);

        Node *temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
};

int main()
{
    // Function to convert nullptr to "0 (nullptr)"
    auto ptrToNum = [](Node* ptr) -> string {
        return (ptr == nullptr) ? "0 (nullptr)" : to_string(ptr->value);
    };

    // Helper function to check test result
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: EmptyList
    {
        cout << "\n------ LinkedList Test: EmptyList ------\n";

        LinkedList list(1);
        list.makeEmpty();
        
        list.printList();
        
        Node* middle = list.findMiddleNode();
        
        cout << "Middle node: " << ptrToNum(middle) << endl;
        
        checkTestResult(middle == nullptr);
    }

    // Test: SingleElement
    {
        cout << "\n------ LinkedList Test: SingleElement ------\n";
        
        LinkedList list(1);
        
        list.printList();
        
        Node* middle = list.findMiddleNode();
        
        cout << "Middle node: " << ptrToNum(middle) << endl;

        checkTestResult(middle == list.getHead());
    }

    // Test: EvenNumberOfElements
    {
        cout << "\n------ LinkedList Test: EvenNumberOfElements ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        
        list.printList();
        
        Node* middle = list.findMiddleNode();
        
        cout << "Middle node: " << ptrToNum(middle) << endl;

        checkTestResult(middle->value == 3);
    }

    // Test: OddNumberOfElements
    {
        cout << "\n------ LinkedList Test: OddNumberOfElements ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        
        list.printList();
        
        Node* middle = list.findMiddleNode();
        
        cout << "Middle node: " << ptrToNum(middle) << endl;
        
        checkTestResult(middle->value == 2);
    }
}
