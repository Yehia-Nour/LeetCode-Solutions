class MyCircularQueue {
private:
    int *arr { };
	int front { 0 };
	int rear { 0 };
	int added_elements { };
    int size; 
public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
    }
	int next(int pos) {
		++pos;
		if (pos == size)
			pos = 0;
		return pos;
	}
    bool enQueue(int value) {
		if (isFull()) return false;
		arr[rear] = value;
		rear = next(rear);
		added_elements++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        
		front = next(front);
		--added_elements;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        if (rear == 0) return arr[size - 1];
        return arr[rear - 1];
    }
    
    bool isEmpty() {
		return added_elements == 0;
    }
    
    bool isFull() {
		return added_elements == size;
    }
    ~MyCircularQueue() {
		delete[] arr;
	}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */