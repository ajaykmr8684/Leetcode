class MyCircularQueue {
public:
    vector<int> data;
    int front = -1;
    int rear = -1;
    int size = 0;
    MyCircularQueue(int k) {
        data.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(size == 0) {
            front = 0;
        }
        rear+= 1;
        rear = rear % data.size();
        data[rear] = value;
        size++;
        return true; 
    }
    
    bool deQueue() {
        if(size == 0) return false;
        front += 1;
        front = front % data.size();
        size--;
        if(size == 0) {
            front = -1;
            rear = -1;
        }
        return true;
    }
    
    int Front() {
        if(size == 0) return -1;
        return data[front];
    }
    
    int Rear() {
        if(size == 0) return -1;
        return data[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == data.size();
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