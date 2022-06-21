class MinStack {
public:
    stack<long long> st;
    long long mn;
    
    MinStack() {
        mn = INT_MAX;
    }
    
    void push(int val) {
        if(st.size()==0){
            st.push(val);
            mn = val;
        }
        else{
            if(val < mn){
                st.push(1LL*2*val-mn);
                mn = val;
            }
            else{
                st.push(val);
            }   
        }
    }
    
    void pop() {
        if(st.size()!=0){
            if(st.top()<mn){
                mn = 2*mn - st.top();
                st.pop();
            }
            else{
                st.pop();
            }
        }
    }
    
    int top() {
        if(st.top()<mn)return mn;
        else return st.top();
    }
    
    int getMin() {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */