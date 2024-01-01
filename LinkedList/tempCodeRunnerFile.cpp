void deleteNode(int index)
        {
            if(index <0 | index >= length)
            {
                return;
            }
            Node* temp = get(index);
            if(index == 0)
            {
                head = nullptr;
                tail = nullptr;
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