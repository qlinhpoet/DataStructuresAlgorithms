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
    int length;
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
    
    //WITHOUT USING THE LENGTH
    Node* findKthFromEnd(int k)
    {
        Node* fast = head;
        Node* slow = head;

        //set fastPrt is fast than slowPrt k-1 Node
        //so while fastPrt is tail => slow is finding Node
        for(int i=0; i<k; i++)
        {
            if(fast == nullptr) return nullptr;
            fast = fast->next;
        }
        while(fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    void removeDuplicates()
    {
        if(head == nullptr) return;

        Node* slow = head;
        while(slow->next != nullptr)
        {
            Node* prefast = slow;
            Node* fast = slow->next;
            while(fast != nullptr)
            {
                if(fast->value == slow->value)
                {
                    prefast->next = fast->next;
                    fast = prefast->next;
                }
                else
                {
                    prefast = fast;
                    fast = fast->next;
                }
            }
            tail = prefast;
            slow = slow->next;
        }
    }
};
static void testremoveDuplicates();
static void TestfindKthFromEnd();
int main()
{   
    LinkedList list(1);
    list.append(2);
    list.append(3);
    cout << list.findKthFromEnd(1)->value << endl;
    testremoveDuplicates();
    //TestfindKthFromEnd();

}

static void testremoveDuplicates() {
    // Helper function for pass/fail
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: RemoveDuplicatesEmptyList
    {
        cout << "\n------ Test: RemoveDuplicatesEmptyList ------\n";
        
        LinkedList list(1);
        list.makeEmpty();
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.removeDuplicates();
        
        cout << "AFTER:     ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head == nullptr);
    }

    // Test: RemoveDuplicatesSingleElement
    {
        cout << "\n------ Test: RemoveDuplicatesSingleElement ------\n";
        
        LinkedList list(1);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.removeDuplicates();
        
        cout << "AFTER:     ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head && head->value == 1);
    }

    // Test: RemoveDuplicatesNoDuplicates
    {
        cout << "\n------ Test: RemoveDuplicatesNoDuplicates ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.removeDuplicates();
        
        cout << "AFTER:     ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head && head->value == 1);
    }

    // Test: RemoveDuplicatesHasDuplicates
    {
        cout << "\n------ Test: RemoveDuplicatesHasDuplicates ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(2);
        list.append(3);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.removeDuplicates();
        
        cout << "AFTER:     ";
        list.printList();
        
        // Check for duplicates
        Node* current = list.getHead();
        bool noDuplicates = true;
        
        while (current && current->next) {
            if (current->value == current->next->value) {
                noDuplicates = false;
                break;
            }
            current = current->next;
        }
        
        checkTestResult(noDuplicates);
    }
    
}

static void TestfindKthFromEnd() 
{
    // Function to convert nullptr to string for easy comparison
    auto ptrToNum = [](Node* ptr) -> string {
        return (ptr == nullptr) ? "nullptr" : to_string(ptr->value);
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
        
        Node* result = list.findKthFromEnd(1);
        
        cout << "Kth from end: " << ptrToNum(result) << endl;
        
        checkTestResult(result == nullptr);
    }

    // Test: KGreaterThanListLength
    {
        cout << "\n------ LinkedList Test: KGreaterThanListLength ------\n";
        
        LinkedList list(1);
        list.append(2);
        
        list.printList();
        
        Node* result = list.findKthFromEnd(3);
        
        cout << "Kth from end: " << ptrToNum(result) << endl;
        
        checkTestResult(result == nullptr);
    }

    // Test: KEqualsListLength
    {
        cout << "\n------ LinkedList Test: KEqualsListLength ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        
        list.printList();
        
        Node* result = list.findKthFromEnd(3);
        
        cout << "Kth from end: " << ptrToNum(result) << endl;
        
        checkTestResult(result && result->value == 1);
    }

    // Test: KLessThanListLength
    {
        cout << "\n------ LinkedList Test: KSecondFromEnd ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);
        
        list.printList();
        
        Node* result = list.findKthFromEnd(2);
        
        cout << "Kth from end: " << ptrToNum(result) << endl;
        
        checkTestResult(result && result->value == 4);
    }
    
}


