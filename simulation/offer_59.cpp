#include <queue>
using namespace std;

class MaxQueue {
private:
    queue<int> que;
    deque<int> deq;
public:
    MaxQueue() {}
    
    int max_value() {
        if (que.empty()) return -1;
        return deq.front();
    }
    void push_back(int value) {
        que.push(value);
        while (!deq.empty() && value > deq.back()) {
            deq.pop_back();
        } // 维护一个递减序列，当最大值出队列时，最大值移位
        deq.push_back(value);
    }
    
    int pop_front() {
        if (que.empty()) return -1;
        if (que.front() == deq.front()) {
            deq.pop_front();
        }
        int front = que.front();
        que.pop();
        return front;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */