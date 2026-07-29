class MinStack {
public:
    vector<int> st;
    vector<int> minst;

    MinStack() {
        
    }
    
    void push(int value) {
        st.push_back(value);
        if(minst.empty()){
            minst.push_back(value);
        }
        else{
            int minval=min(minst.back(),value);
            minst.push_back(minval);
        }
    }
    
    void pop() {
            st.pop_back();
            minst.pop_back();
        
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minst.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */