#include <stack>
#include <climits>
#include <iostream>
using namespace std;

class QueueUsingTwoStacks {
private:
    stack<int> stack1, stack2;

public:
    int front() {
        //move data from stack 1 to stack2, stack 2 will be become a queue
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty()) {
            return INT_MIN;
        }

        return stack2.top();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    //add items to the end of the simulated queue
    void enqueue(int newItem)
    {
        stack1.push(newItem);

    }

    //dequeue operation is used to remove the front-most item
    void dequeue()
    {
        //move data from stack 1 to stack2, stack 2 will be become a queue
        if(stack2.empty())
        {
            while(stack1.empty() != true)
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) return;
        stack2.pop();
    }

    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This method adds a new value to the end of the    |
    //   |   queue (enqueue) using 'stack1'.                   |
    //   | - Return type: void                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use 'stack1' to enqueue a new value.              |
    //   | - Simply push the new value onto 'stack1'.          |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    
};

static void testEnqueue() {
    cout << "\n----- Test: Enqueue to Empty Queue -----\n";
    {
        QueueUsingTwoStacks queue;
        cout << "Initial state: empty queue\n";
        cout << "Enqueuing value of 5 to an empty queue:\n";
        queue.enqueue(5);
        cout << "Front result: " << queue.front() << " - EXPECTED: 5\n";
        cout << "Is empty: " << (queue.isEmpty() ? "yes" : "no") << " - EXPECTED: no\n";
        cout << (!queue.isEmpty() && queue.front() == 5 ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Multiple Enqueues -----\n";
    {
        QueueUsingTwoStacks queue;
        cout << "Enqueuing values of 1, 2, and 3 to the queue:\n";
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        cout << "Front result: " << queue.front() << " - EXPECTED: 1\n";
        cout << "Is empty: " << (queue.isEmpty() ? "yes" : "no") << " - EXPECTED: no\n";
        cout << (!queue.isEmpty() && queue.front() == 1 ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Enqueue Large Numbers -----\n";
    {
        QueueUsingTwoStacks queue;
        cout << "Enqueuing maximum integer value:\n";
        queue.enqueue(INT_MAX);
        cout << "Front result: " << queue.front() << " - EXPECTED: " << INT_MAX << "\n";
        cout << "Is empty: " << (queue.isEmpty() ? "yes" : "no") << " - EXPECTED: no\n";
        cout << (!queue.isEmpty() && queue.front() == INT_MAX ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Enqueue Negative Numbers -----\n";
    {
        QueueUsingTwoStacks queue;
        cout << "Enqueuing values of -5 and -10 to the queue:\n";
        queue.enqueue(-5);
        queue.enqueue(-10);
        cout << "Front result: " << queue.front() << " - EXPECTED: -5\n";
        cout << "Is empty: " << (queue.isEmpty() ? "yes" : "no") << " - EXPECTED: no\n";
        cout << (!queue.isEmpty() && queue.front() == -5 ? "PASS\n" : "FAIL\n");
    }
}

static void testDequeue() {
    cout << "\n----- Test: Dequeue from Empty Queue -----\n";
    {
        QueueUsingTwoStacks queue;
        cout << "Initial state: empty queue\n";
        queue.dequeue();
        cout << "Front result after dequeue: " << queue.front() << " - EXPECTED: " << INT_MIN << "\n";
        cout << "Is empty: " << (queue.isEmpty() ? "yes" : "no") << " - EXPECTED: yes\n";
        cout << (queue.isEmpty() && queue.front() == INT_MIN ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Dequeue After Multiple Enqueues -----\n";
    {
        QueueUsingTwoStacks queue;
        cout << "Enqueuing values of 1, 2, and 3 to the queue:\n";
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        cout << "Front result before dequeue: " << queue.front() << " - EXPECTED: 1\n";
        
        queue.dequeue();
        cout << "Front result after 1st dequeue: " << queue.front() << " - EXPECTED: 2\n";
        queue.dequeue();
        cout << "Front result after 2nd dequeue: " << queue.front() << " - EXPECTED: 3\n";
        cout << (!queue.isEmpty() && queue.front() == 3 ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Maintain Order After Multiple Operations -----\n";
    {
        QueueUsingTwoStacks queue;
        cout << "Enqueuing values of 1 and 2, then dequeuing, then enqueuing values of 3 and 4, then dequeuing again:\n";
        queue.enqueue(1);
        queue.enqueue(2);
        queue.dequeue();
        queue.enqueue(3);
        queue.enqueue(4);
        queue.dequeue();
        
        cout << "Front result: " << queue.front() << " - EXPECTED: 3\n";
        queue.dequeue();
        cout << "Front result after dequeue: " << queue.front() << " - EXPECTED: 4\n";
        queue.dequeue();
        cout << "Is empty: " << (queue.isEmpty() ? "yes" : "no") << " - EXPECTED: yes\n";
        cout << "Front result after all dequeues: " << queue.front() << " - EXPECTED: " << INT_MIN << "\n";
        cout << (queue.isEmpty() && queue.front() == INT_MIN ? "PASS\n" : "FAIL\n");
    }
    
}

int main()
{
    testDequeue();
    return 0;
}