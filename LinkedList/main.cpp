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

        void append(int value)
        {
            //them node vao cuoi
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
    LinkedList ll(0);
    ll.prepend(1);
    ll.printList();
    return 0;
}