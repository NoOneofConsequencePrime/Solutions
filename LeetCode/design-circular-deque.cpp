class MyCircularDeque {
private:
    vector<int> dq;
    int a, b, k, cnt;
public:
    MyCircularDeque(int k) {
        dq = vector<int>(k, -1);
        a = b = cnt = 0;
        this->k = k;
    }
    
    bool insertFront(int value) {
        if (!isFull()) {
            a = (a == 0)? k-1 : a-1;
            if (isEmpty()) {b = a;}
            dq[a] = value;
            cnt++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if (!isFull()) {
            b = (b == k-1)? 0 : b+1;
            if (isEmpty()) {a = b;}
            dq[b] = value;
            cnt++;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if (!isEmpty()) {
            dq[a] = -1;
            a = (a == k-1)? 0 : a+1;
            cnt--;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if (!isEmpty()) {
            dq[b] = -1;
            b = (b == 0)? k-1 : b-1;
            cnt--;
            return true;
        }
        return false;
    }
    
    int getFront() {
        return isEmpty()? -1 : dq[a];
    }
    
    int getRear() {
        return isEmpty()? -1 : dq[b];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == k;
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