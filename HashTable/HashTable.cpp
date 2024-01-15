#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int value;
    string key;
    Node* next;

public:
    Node(string key, int value)
    {
        this->value = value;
        this->key = key;
        next = nullptr;
    }
};

class HashTable
{
private:
    static const int SIZE = 7;
    Node* dataMap[SIZE];
public:
    HashTable()
    {
        for(int i=0; i<SIZE; i++)
        {
            dataMap[i] = nullptr;
        }
    }

    ~HashTable()
    {
        for(int i=0; i<SIZE; i++)
        {
            Node* temp = dataMap[i];
            while(temp)
            {
                dataMap[i] = dataMap[i]->next;
                delete temp;
                temp = dataMap[i];
            }
        }
    }

    int hash(string key)
    {
        int hash = 0;
        for(int i=0; i<key.length(); i++)
        {
            int ascciKeyValue = int(key[i]);
            hash = (hash + ascciKeyValue*23) % SIZE;
        }
        return hash;
    }

    void set(string key, int value)
    {
        //get index
        int index = hash(key);
        Node* newNode = new Node(key, value);
        Node* temp = dataMap[index];
        //Check if the dataMap entry at the calculated index is nullptr
        if(temp == nullptr)
        {
            dataMap[index] = newNode;
            return;
        }
        //If the key is found, update its value and return.
        else if(temp->key == key)
        {
            temp->value = value;
            return;
        }
        //If the key is not found, insert the new node at the end of the linked list.
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }

    int get(string key)
    {
        //get index
        int index = hash(key);
        Node* temp = dataMap[index];
        while(temp)
        {
            if(temp->key == key)
            {
                return temp->value;
            }
            temp=temp->next;
        }
        //// If the key is not found in the linked list, return 0
        return 0;
    }

    void printTable()
    {
        for(int i=0; i<SIZE; i++)
        {
            Node* temp = dataMap[i];
            cout <<"dataMap_" << i << ":";
            while(temp)
            {
               cout << "{" << temp->key << "," << temp->value << "}";
               temp = temp->next;
            }
            cout << endl;
        }
    }

    vector<string> keys()
    {
            vector<string> allkeys;
            for(int i=0; i<SIZE; i++)
            {
                if(dataMap[i])
                {
                    Node* temp = dataMap[i];
                    while(temp)
                    {
                        allkeys.push_back(temp->key);
                        temp=temp->next;
                    }
                }
            }
            return allkeys;
    }
};
#define max 4
int main()
{
    {
        cout << "\n----- Test: Get Large Number of Values -----\n";
        HashTable ht;
        for(int i = 0; i < max; i++) {
            ht.set("key" + to_string(i), i);
        }
        bool pass = true;
        for(int i = 0; i < max; i++) {
            if(ht.get("key" + to_string(i)) != i) {
                cout <<ht.get("key" + to_string(i)) << endl;
                pass = false;
                break;
            }
        }
        cout << "Getting a large number of values - EXPECTED: 0 to 99\n";
        cout << (pass ? "PASS\n" : "FAIL\n");

        for(int i = 0; i<ht.keys().size(); i++)
        {
            cout << ht.keys()[i]<< endl;
        }
    }
}