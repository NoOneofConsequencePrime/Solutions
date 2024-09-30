class CustomStack {
private:
    vector<int> stk;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (stk.size() < maxSize) {stk.push_back(x);}
    }
    
    int pop() {
        if (stk.size() == 0) {return -1;}
        int ret = stk[stk.size()-1];
        stk.pop_back(); return ret;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, (int)stk.size()); i++) {
            stk[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */