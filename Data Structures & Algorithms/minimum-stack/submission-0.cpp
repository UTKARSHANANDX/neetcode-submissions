class MinStack {
public:
    stack<int> stack1;
    stack<int> minStack;
public:

    MinStack() {
        
    }
    
    void push(int val) {
        stack1.push(val);
        val = min(val,minStack.empty() ? val: minStack.top());
        minStack.push(val);
        
    }
    
    void pop() {
        stack1.pop();
        minStack.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
