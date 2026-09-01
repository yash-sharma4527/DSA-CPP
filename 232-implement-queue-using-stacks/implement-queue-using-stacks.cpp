class MyQueue {
    stack<int> in;
    stack<int> out;
    int peekElement;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(in.empty()){
            peekElement = x;
        }

        in.push(x);
    }
    
    int pop() {
        if(!out.empty()){
            int n = out.top();
            out.pop();
            return n;
        }
        else{
            while(in.size() != 1){
                out.push(in.top());
                in.pop();
            }

            int n = in.top();
            in.pop();
            return n;
        }
    }
    
    int peek() {
        if(!out.empty()){
            return out.top();
        }
        else{
            return peekElement;
        }
    }
    
    bool empty() {
        if(in.empty() && out.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */