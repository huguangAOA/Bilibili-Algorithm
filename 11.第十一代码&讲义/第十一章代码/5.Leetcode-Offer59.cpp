class MaxQueue {
public:
    queue<int> q;
    deque<int> mq;
    MaxQueue() {}
    
    int max_value() {
        if (q.empty()) return -1;
        return mq.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while (!mq.empty() && value > mq.back()) mq.pop_back();
        mq.push_back(value);
        return ;
    }
    
    int pop_front() {
        if (q.empty()) return -1;
        int val = q.front();
        q.pop();
        if (mq.front() == val) mq.pop_front();
        return val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */