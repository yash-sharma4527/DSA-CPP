class MyCircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if(this->isFull()){
            return false;
        }
        else if(this->isEmpty()){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear+1)%size;
        }

        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(this->isEmpty()){
            return false;
        }

        else if(front == rear){
            front = -1;
            rear = -1;
        }

        else{
            front = (front+1)%size ;
        }
        return true;
    }
    
    int Front() {
        if(this->isEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(this->isEmpty()){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear+1)%size == front;
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