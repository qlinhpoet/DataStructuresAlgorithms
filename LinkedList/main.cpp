#include <iostream>
#include <vector>
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
            // delete cac node tu dau toi cuoi.
            Node *temp = head;
            while(head)
            {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList()
        {
            //in cac node tu dau toi cuoi
            Node *temp = head;
            while(temp != nullptr)
            {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        //them node vao cuoi
        void append(int value)
        {
            Node *newNode = new Node(value);
            Node *temp = head;
            if(length == 0)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }
        //them node vao dau
        void prepend(int value)
        {
            Node *newNode = new Node(value);
            if(length < 0) return;
            if(length == 0)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }
        //xoa node cuoi
        void deleteLast()
        {
            
            if(length == 0)
            {
                return;
            }
            Node *temp = head;
            if(length == 1)
            {
                head = nullptr;
                head = nullptr;
            }
            else
            {
                Node *pre = head;
                while(temp->next)
                {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
            }
            delete temp;
            length++;
        }
        //xoa node dau
        void deleteFirst()
        {
            
            if(length <= 0)
            {
                return;
            }
            Node *temp = head;
            if(length == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
            }
            delete temp;
            length--;
        }
        
        Node* get(int index)
        {
            if(index < 0 || index >= length)
            {
                return nullptr;
            }
            Node *temp = head;
            for(int i=0; i<index; i++)
            {
                temp = temp->next;
            }
            return temp;
        }

        bool set(int index, int value)
        {
            if(index < 0 || index>= length)
            {
                return false;
            }
            Node *temp = head;
            for(int i=0; i<index; i++)
            {
                temp = temp->next;
            }
            temp->value = value;
            return true;
        }
        //them node vao vi tri bat ky
        bool insert(int index, int value)
        {
            if(index < 0 || index > length)
            {
                return false;
            }
            if(index == 0)
            {
                prepend(value);
                return true;
            }
            else
            {
                Node *newNode = new Node(value);
                Node *temp = head;
                for(int i=0; i+1< index; i++)
                {
                    temp = temp->next;

                }
                newNode->next = temp->next;
                temp->next = newNode;
                length++;
                return true;
            }
        }

        void deleteNode(int index)
        {
            if(index <0 | index >= length)
            {
                return;
            }
            if(length == 0)
            {
                head = nullptr;
                tail = nullptr;
                return;
            }
            Node* temp = get(index);
            if(index == 0)
            {
                head = head->next;
                delete temp;
                
            }
            else
            {
                Node* pre=get(index-1);
                pre->next = temp->next;
                delete temp;
            }
            length--;
            return;

        }
        //dao nguoc linked list
        void reverse()
        {
            if(length == 0 || length == 1)
            {
                return;
            }
            Node* temp = head;
            head = tail;
            tail = temp;
            Node *before = nullptr;
            Node *after = temp->next;
            while(temp)
            {
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
            }

        }

        void makeEmpty()
        {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
        }

        Node* getHead()
        {
            return head;
        }

        Node * getTail()
        {
            return tail;
        }

        int getLength()
        {
            return length;
        }

        Node *findMiddleNode()
        {
            
        }
        void bubbleSort()
        {
            if(length < 2) return;
            Node* temp = nullptr;
            for(int i=length; i>0; i--)
            {
                temp = head;
                for(int j=0; j<i-1; j++)
                {
                    if(temp->value > temp->next->value)
                    {
                        int tempValue = temp->value;
                        temp->value = temp->next->value;
                        temp->next->value = tempValue;
                    }
                    temp = temp->next;
                }
            }
        }

        //selection sort - only sort value of node.
        void selectionSort()
        {
            if(length < 2) return;
            Node* temp1 = head;
            while(temp1->next != nullptr)
            {
                Node* minNode = temp1;
                Node* temp2 = temp1;
                while(temp2->next != nullptr)
                {
                    temp2 = temp2->next;
                    if(minNode->value > temp2->value)
                    {
                        minNode = temp2;
                    }
                }
                //swap min value
                if(minNode != temp1)
                {
                    int minValue = minNode->value;
                    minNode->value = temp1->value;
                    temp1->value = minValue;
                }
                temp1 = temp1->next;
            }
        }

        //insertion sort - node(included value and next) is sorted follow its value, head and tail also are updated.
        void insertionSort() {
            if (length < 2) return;
        
            Node* sortedListHead = head;
            Node* unsortedListHead = head->next;
            sortedListHead->next = nullptr;
        
            while (unsortedListHead != nullptr) {
                Node* current = unsortedListHead;
                unsortedListHead = unsortedListHead->next;
        
                if (current->value < sortedListHead->value)
                {
                    current->next = sortedListHead;
                    sortedListHead = current;
                } 
                else 
                {
                    Node* searchPointer = sortedListHead;
                    while (searchPointer->next != nullptr && current->value > searchPointer->next->value) {
                        searchPointer = searchPointer->next;
                    }
                    current->next = searchPointer->next;
                    searchPointer->next = current;
                }
            }
        
            head = sortedListHead;
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            tail = temp;
        }

        void printAll()
        {

            Node* temp = head;
            cout << "head:"<< head << endl ;
            while(temp)
            {
                cout << temp << " : " << temp->value << endl;
                temp = temp->next;
            }
            cout << "tail:"<< tail << endl ;
        }
}; 

void checkTestResult(bool condition)
{
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main()
{
    // Test 0: init without creat new node
    {
        //LinkedList test0;
    }


    //Prepend: Test
    LinkedList ll(3);
    ll.prepend(1);
    ll.prepend(5);
    ll.prepend(6);
    ll.prepend(2);
    ll.prepend(4);
    ll.printAll();
    cout << endl;
    ll.insertionSort();
    ll.printAll();

    return 0;
}