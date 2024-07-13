#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Node
{
private:
    int key;
    bool value;
    Node* next;
};

class HashTable
{
private:
    static const int SIZE = 7;
    int dataMap[SIZE] = {};

public:
    HashTable()
    {
        for(int i=0; i<SIZE; i++) dataMap[i] = 0;
    }

    ~HashTable()
    {

    }

    int hash(string key)
    {
        int hashvalue = 0;
        for(int i=0; i<key.length(); i++)
        {
            int ascciKeyValue = int(key[i]);
            hashvalue = (hashvalue + ascciKeyValue*23) % SIZE;
        }
        return hashvalue;
    }

    void insert(string key, int value)
    {
        int index = hash(key);
        dataMap[index] = value;
    }

    int get(string key)
    {
        int index = hash(key);
        return dataMap[index];

    }
};

int main()
{
    HashTable myht;
    cout << myht.get("muoi") << endl;
    myht.insert("muoi", 10);
    cout << myht.get("muoi") << endl;
    cout <<"hello world\n";
    return 0;
}
