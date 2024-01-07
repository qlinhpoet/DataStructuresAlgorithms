#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }    

};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;
    int length;
public:
    DoublyLinkedList(int value)
    {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList()
    {
        Node*temp = head;
        while(temp)
        {
            cout << temp->value <<endl;
            temp = temp->next;
        }
    }

    void append(int value)
    {
        Node* newNode = new Node(value);
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node* temp = head;
            while(temp->next)
            {
                temp = temp->next;

            }
            temp->next = newNode;
            tail = newNode;
            newNode->prev = temp;
        }
        length++;
    }

    void deleteLast()
    {
        if(length <= 0)
        {
            return;
        }
        else if(length == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* temp = head;
            while(temp->next)
            {
                temp = temp->next;
            }
            tail = temp->prev;
            tail->next = nullptr;
            delete temp;
            
        }
        length--;
        return;
    }

    void prepend(int value)
    {
        Node* newNode = new Node(value);
        if(length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deleteFirst()
    {
        Node* temp = head;
        if(length <= 1)
        {
            delete temp;
            head = nullptr;
            tail = nullptr;
            length = 0;
        }
        else
        {
            head = temp->next;
            delete temp;
            head->prev = nullptr;
            length--;
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

    void makeEmpty()
    {
        Node* temp = head;
        while(temp)
        {
            head=head->next;
            delete temp;
            temp = head;
        }
    }
    int getLength()
    {
        return length;
    }

    Node* get(int index)
    {
        if(index < 0 || index >= length)
        {
            return nullptr;
        }

        Node* temp = head;
        
        if(index < length/2)
        {
            for(int i=0; i<index; i++)
            {
                temp = temp->next;
            }
        }
        else
        {
            temp = tail;
            for(int i=length-1; i>index; i--)
            {
                temp=temp->prev;
            }
        }
        
        return temp;
    }

    bool set(int index, int value)
    {
        Node* temp = get(index);
        if(temp == nullptr)
        {
            return false;
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
        Node* newNode = new Node(value);
        Node* temp = head;
        
        if(index == 0 || length == 0)
        {
            prepend(value);
        }
        else
        {
            for(int i=0; i<index-1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            if(newNode->next != nullptr)
            {
                newNode->next->prev = newNode;
            }
            else
            {
                tail = newNode;
            }
            length++;
        }
        
        return true;
    }

    void deleteNode(int index)
    {
        if(index<0 || index >= length )//|| length==0 => alway return with all value of index
        {
            return;
        }
        if(index == 0) return deleteFirst();
        if(index == length-1) return deleteLast();  //length alway >= 1 at this step.
        Node* temp = get(index);
        Node* before = temp->prev;
        Node* after = temp->next;
        before->next = after;
        after->prev = before;
        delete temp;
        length--;
        return;
    }

    void swapValueFirstLast()
    {
        if (length < 2) return;
        int temp = head->value;
        head->value = tail->value;
        tail->value = temp;
    }

    void swapFirstLast()
    {
        if(length == 0 || length == 1)
        {
            return;
        }
        Node* temp = head;
        if(length == 2)
        {
            head = tail;
            tail = head;
            return;
        }
        
        tail->prev->next = head;
        head->next->prev = tail;
        head->prev = tail->prev;
        tail->next = head->next;
        head->next = nullptr;
        tail->prev = nullptr;
        head = tail;
        tail = head;
    }

        void reverse()
        {
            Node* temp = head;
            head = tail;
            tail = temp;
            for(int i=0; i<length; i++)
            {
                Node* temp2 = temp->next;
                temp->next = temp->prev;
                temp->prev = temp2;
                temp = temp2;
            }
        }
};

int main()
{
    // Function to convert nullptr to 0 for comparison
    auto ptrToNum = [](Node* ptr) -> string {
        return (ptr == nullptr) ? "0 (nullptr)" : to_string(ptr->value);
    };

    DoublyLinkedList dll(0);
    dll.append(1);
    dll.append(2);
    dll.append(3);
    cout << dll.getHead() << endl;
    cout << dll.getTail() << endl;
    dll.printList();
    dll.swapFirstLast();
    cout << dll.getHead() << endl;
    cout << dll.getTail() << endl;
    dll.printList();

}