#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node* right;
    Node* left;

    Node(int value)
    {
        this->value = value;
        right = nullptr;
        left = nullptr;
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
};

int main()
{
    return 0;
}