class MinStack {
public:
    /** initialize your data structure here. */
    vector<pair<int,int> > stk;
    int m;
    int size;
    MinStack() 
    {
        //vector<int> stk;
        m = 0;
        size=0;
        
    }
    
    void push(int x) 
    {
        
        if(size!=0)
            m= min(m,x);
        else
            m=x;
        stk.push_back({x,m});
        size++;
    }
    
    void pop() 
    {
        
        if(size>=2)
            m = stk[size-2].second;
        //else
        stk.pop_back();
            
         size--;
        //turn r
    }
    
    int top() 
    {
        return stk[size -1].first;

    }
    
    int getMin() 
    {
        return m;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */