#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

class Node
{
    public:
    int value;
    Node* left;
    Node* right;

    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
private:
    Node* root;
public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    BinarySearchTree(int value)
    {
        Node* newNode = new Node(value);
        root = newNode;
    }

    void destroy(Node* currentNode)
    {
        if(currentNode == nullptr) return;
        if(currentNode->left) destroy(currentNode->left);
        if(currentNode->right) destroy(currentNode->right);
        delete currentNode;
    }

    Node* getRoot()
    {
        return root;
    }

    ~BinarySearchTree()
    {
        destroy(root);
    }

    bool insert(int value)
    {
        Node* newNode = new Node(value);
        if(root == nullptr)
        {
            root = newNode;
        }
        else
        {
            Node* temp = root;
            while(temp)
            {
                if(newNode->value > temp->value)
                {
                    if(temp->right)
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        temp->right = newNode;
                        temp = nullptr;
                    }
                }
                else if(newNode->value < temp->value)
                {
                    if(temp->left)
                    {
                        temp = temp->left;
                    }
                    else
                    {
                        temp->left = newNode;
                        temp = nullptr;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool contains(int value)
    {
            Node* temp = root;
            while(temp)
            {
                if(temp->value > value)
                {
                    temp = temp->left;
                }
                else if(temp->value < value)
                {
                    temp = temp->right;
                }
                else
                {
                    return true;
                }
            }
            return false;
    }

    void BFS();

    void DFSPreOrder(Node* currentNode)
    {
        //if(currentNode == nullptr) return;
        // print current node's value
        cout << currentNode->value << " ";
        // traverse left subtree recursively
        if(currentNode->left != nullptr)
        {
            DFSPreOrder(currentNode->left);
        }
        // traverse right subtree 
        if(currentNode->right != nullptr)
        {
            DFSPreOrder(currentNode->right);
        }
    }

    //overload function incase root is private.
    void DFSPreOrder()
    {
        DFSPreOrder(root);
    }

    void DFSPostOrder(Node* currentNode)
    {
        if(currentNode == nullptr) return;
            
        if(currentNode->left != nullptr)
        {
            DFSPostOrder(currentNode->left);
        }
        if(currentNode->right != nullptr)
        {
            DFSPostOrder(currentNode->right);
        }
        cout << currentNode->value << " ";
    }

    //overload function incase root is private.
    void DFSPostOrder()
    {
        DFSPostOrder(root);
    }

    void DFSInOrder(Node* currentNode)
    {
        if(currentNode == nullptr) return;
        
        if(currentNode->left != nullptr)
        {
            DFSInOrder(currentNode->left);
        }
        cout << currentNode->value <<" ";
        if(currentNode->right != nullptr)
        {
            DFSInOrder(currentNode->right);
        }
    }

    //overload function incase root is private.
    void DFSInOrder()
    {
        DFSInOrder(root);
    }
};

void BinarySearchTree::BFS()      //breadth first search
{
    if(root == nullptr) return;
    //template - creat new queue
    queue<Node*> myQueue;
    //add root of BST into queue
    myQueue.push(root);
    //if root != nullptr -> queue size = 1;
    while(myQueue.size() > 0)
    {
        Node* currentNode = myQueue.front();
        myQueue.pop();
        cout << currentNode->value <<" ";
        if(currentNode->left != nullptr)
        {
            myQueue.push(currentNode->left);
        }
        if(currentNode->right != nullptr)
        {
            myQueue.push(currentNode->right);
        }
    }
}

bool isSameTree(Node* p, Node* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        bool ret = true;
        ret &= p->value == q->value;
        ret &= isSameTree(p->left, q->left);
        ret &= isSameTree(p->right, q->right);
        return ret;
}
bool isSymmetric(Node* root) {
        if(root == nullptr) return true;
        std::function<bool(Node*, Node*)> helpfc = [&](Node* p, Node* q)
        {
            if(p==nullptr && q==nullptr) return true;
            if(p==nullptr || q==nullptr) return false;
            return (p->value == q->value) && helpfc(p->left, q->right) && helpfc(p->right, q->left);
        };

        return helpfc(root->left, root->right);
}

int main()
{
    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(2);

    cout << isSymmetric(p);
    return 0;
}