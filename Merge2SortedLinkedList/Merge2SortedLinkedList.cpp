#include <iostream>

using namespace std;

class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }

        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

       void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }
        
        void merge(LinkedList& otherList)
        {
            Node* dummyNode = new Node(0);
            Node* current = dummyNode;

            Node* thisHead = this->getHead();
            Node* otherHead = otherList.getHead();

            while( thisHead && otherHead)
            {
                if(thisHead->value < otherHead->value)
                {
                    current->next = thisHead;
                    thisHead = thisHead->next;
                }
                else
                {
                    current->next = otherHead;
                    otherHead = otherHead->next;
                }
                current = current->next;
            }
            while(thisHead)
            {
                current->next = thisHead;
                thisHead = thisHead->next;
                current = current->next;
            }
            while(otherHead)
            {
                current->next = otherHead;
                otherHead = otherHead->next;
                current = current->next;
            }
            this->head = dummyNode->next;
            this->tail = current;
            this->length += otherList.getLength();
            delete dummyNode;
            //head and tail is private.
            otherList.head = nullptr;
            otherList.tail = nullptr;
        }

		//   +=====================================================+
		//   |                WRITE YOUR CODE HERE                 |
		//   | Description:                                        |
		//   | - This method merges two sorted linked lists        |
		//   |   into a single sorted linked list.                 |
		//   | - Utilizes a dummy node to simplify merging.        |
		//   |                                                     |
		//   | Return type: void                                   |
		//   | - Modifies the list in place.                       |
		//   | - Sets the 'head' and 'tail' pointers correctly.    |
		//   |                                                     |
		//   | Tips:                                               |
		//   | - Uses a dummy node for easier linking.             |
		//   | - Check output from Test.cpp in "User logs".        |
		//   +=====================================================+
		
};


int main() {

    // Check test result: PASS or FAIL
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test 1: MergeTwoEmptyLists
    {
        cout << "\n------ Test1: MergeTwoEmptyLists ------\n";

        LinkedList list1(0);
        list1.deleteFirst();
        LinkedList list2(0);
        list2.deleteFirst();

        cout << "List1: ";
        list1.printList();

        cout << "List2: ";
        list2.printList();

        list1.merge(list2);

        cout << "Merged: ";
        list1.printList();

        checkTestResult(list1.getLength() == 0);
    }

    // Test 2: MergeEmptyAndNonEmptyLists
    {
        cout << "\n------ Test2: MergeEmptyAndNonEmptyLists ------\n";

        LinkedList list1(0);
        list1.deleteFirst();
        LinkedList list2(5);

        cout << "List1: ";
        list1.printList();

        cout << "List2: ";
        list2.printList();

        list1.merge(list2);

        cout << "Merged: ";
        list1.printList();

        checkTestResult(list1.getLength() == 1 &&
                        list1.getHead()->value == 5 &&
                       list1.getTail()->value == 5);
    }

    // Test 3: MergeTwoNonEmptyLists
    {
        cout << "\n------ Test3: MergeTwoNonEmptyLists ------\n";

        LinkedList list1(3);
        list1.append(4);
        LinkedList list2(1);
        list2.append(2);

        cout << "List1: ";
        list1.printList();

        cout << "List2: ";
        list2.printList();

        list1.merge(list2);

        cout << "Merged: ";
        list1.printList();

        checkTestResult(list1.getLength() == 4);  // Additional checks could be added
    }

    // Test 4: MergeDifferentLengthLists
    {
        cout << "\n------ Test4: MergeDifferentLengthLists ------\n";

        LinkedList list1(1);
        LinkedList list2(2);
        list2.append(3);
        list2.append(4);

        cout << "List1: ";
        list1.printList();

        cout << "List2: ";
        list2.printList();

        list1.merge(list2);

        cout << "Merged: ";
        list1.printList();

        checkTestResult(list1.getLength() == 4);  // Additional checks could be added
    }
    
}