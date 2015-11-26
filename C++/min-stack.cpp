class MinStack {
    stack<int> mystack;
    long min;
public:
    void push(int x) {
        if(mystack.empty()){
            mystack.push(0L);
            min = x;
        } else{
            mystack.push(x - min);
            if(x < min)
                min = x;
        }
    }

    void pop() {
        if(mystack.empty())
            return;
        long val = mystack.top();
        mystack.pop();
        if(val < 0)
            min -= val;
    }

    int top() {
        long top = mystack.top();
        if(top > 0)
            return (int)(min + top);
        else
            return (int)min;
    }

    int getMin() {
        return (int)min;
    }
};
