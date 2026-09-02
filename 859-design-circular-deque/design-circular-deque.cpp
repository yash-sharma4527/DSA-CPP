class MyCircularDeque {
    int* arr;
    int n;
    int front;
    int rear;
    int count;
public:
    MyCircularDeque(int k) {
        n = k;
        arr = new int[k];
        front = -1;
        rear = -1;
        count = 0;
    }
    
    bool insertFront(int value) {
        if(this->isFull()){
            return false;
        }

        else if(front == -1){
            front = 0;
            rear = 0;
        }

        else{
            front = (front+n-1)%n;
        }

        arr[front] = value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(this->isFull()){
            return false;
        }
        else if(front == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear+1)%n;
        }

        arr[rear] = value;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(this->isEmpty()){
            return false;
        }
        
        else if(rear == front){
            front = -1;
            rear = -1;
        }

        else{
            front = (front+1)%n;
        }
        
        count--;
        return true;
    }
    
    bool deleteLast() {
        if(this->isEmpty()){
            return false;
        }

        else if(rear == front){
            front = -1;
            rear = -1;
        }

        else{
            rear = (rear+n-1)%n;
        }

        count--;
        return true;
    }
    
    int getFront() {
        if(this->isEmpty()){
            return -1;
        }

        return arr[front];
    }
    
    int getRear() {
        if(this->isEmpty()){
            return -1;
        }

        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return count == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */