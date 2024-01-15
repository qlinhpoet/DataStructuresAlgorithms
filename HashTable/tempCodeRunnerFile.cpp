void set(string key, int value)
    {
        int index = hash(key);
        Node* newNode = new Node(string key, int value);
        Node* temp = dataMap[index];
        Node* before = temp;
        if(temp == nullptr)
        {
            dataMap[index] = newNode;
            return;
        }
        while(temp)
        {
            if(temp->key == key)
            {
                temp->value = value;
                return;
            }
            before = temp;
            temp = temp->next;
        }
        before->next = newNode;
        return;
    }