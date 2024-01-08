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

    bool myhasLoop()
    {
        Node* temp = head;
        Node* temp2 = head;
        while(temp != nullptr)
        {
            temp=temp->next;
            do
            {
                if(temp == temp2)
                {
                    return true;
                }
                else
                {
                    temp2 = temp2->next;
                }
            }
            while(temp2 != temp);
            temp2 = head;
        }
        return false;
    }

    bool hasLoop()
    {
        Node* slow = head;
        Node* fast = head;

        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow)
            {
                return true;
            }
        }
        return false;
    }

    Node* getHead()
    {
        return head;
    }

    Node* getTail()
    {
        return tail;
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
    // Function to convert boolean to string for easy comparison
    auto boolToStr = [](bool val) -> string {
        return val ? "True" : "False";
    };

    // Helper function to check test result
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: EmptyListHasLoop
    {
        cout << "\n------ LinkedList Test: EmptyListHasLoop ------\n";

        LinkedList list(1);
        list.makeEmpty();

        list.printList();

        bool hasLoop = list.hasLoop();

        cout << "Has loop: " << boolToStr(hasLoop) << endl;

        checkTestResult(!hasLoop);
    }

    // Test: SingleElementNoLoop
    {
        cout << "\n------ LinkedList Test: SingleElementNoLoop ------\n";

        LinkedList list(1);

        list.printList();

        bool hasLoop = list.hasLoop();

        cout << "Has loop: " << boolToStr(hasLoop) << endl;

        checkTestResult(!hasLoop);
    }

    // Test: MultipleElementsNoLoop
    {
        cout << "\n------ LinkedList Test: MultipleElementsNoLoop ------\n";

        LinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);

        list.printList();

        bool hasLoop = list.hasLoop();

        cout << "Has loop: " << boolToStr(hasLoop) << endl;

        checkTestResult(!hasLoop);
    }

    // Test: SingleElementWithLoop
    {
        cout << "\n------ LinkedList Test: SingleElementWithLoop ------\n";

        LinkedList list(1);
        Node* tail = list.getTail();
        tail->next = list.getHead();

        // Can't print the list because it has a loop!

        bool hasLoop = list.hasLoop();

        cout << "Has loop: " << boolToStr(hasLoop) << endl;

        tail->next = nullptr;  // Break the loop

        checkTestResult(hasLoop);
    }

    // Test: MultipleElementsWithLoop
    {
        cout << "\n------ LinkedList Test: MultipleElementsWithLoop ------\n";

        LinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        Node* tail = list.getTail();
        tail->next = list.getHead();

        // Can't print the list because it has a loop!

        bool hasLoop = list.hasLoop();

        cout << "Has loop: " << boolToStr(hasLoop) << endl;

        tail->next = nullptr;  // Break the loop

        checkTestResult(hasLoop);
    }

    cout << "end" ;

}
