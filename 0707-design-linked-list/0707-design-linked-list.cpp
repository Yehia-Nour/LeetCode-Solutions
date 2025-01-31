struct Node {
    int data { };
    Node *next { };
    Node(int data) : data(data) {}
};

class MyLinkedList {
private:
    Node *head { };
    Node *tail { };
    int length = 0;

public:
    MyLinkedList() {}

    int get(int index) {
        if (index >= length || index < 0) return -1;
        Node *curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->data;
    }

    void addAtHead(int val) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (!tail) tail = newNode;
        ++length;
    }

    void addAtTail(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        ++length;
    }

    void addAtIndex(int index, int val) {
        if (index > length || index < 0) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == length) {
            addAtTail(val);
            return;
        }
        
        Node *newNode = new Node(val);
        Node *curr = head;
        for (int i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        ++length;
    }

    void deleteAtIndex(int index) {
        if (index >= length || index < 0) return;
        
        Node *prev = nullptr;
        Node *curr = head;

        if (index == 0) {
            head = head->next;
            delete curr;
            if (--length == 0) tail = nullptr;
            return;
        }

        for (int i = 0; i < index; ++i) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if (curr == tail) tail = prev;
        delete curr;
        --length;
    }

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->gtailet(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */