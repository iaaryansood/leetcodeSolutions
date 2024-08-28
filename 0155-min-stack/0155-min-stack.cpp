class MinStack {
    vector<pair<int,int>> ans;
    int minimum;
    public:
    MinStack() {
        this->minimum=INT_MAX;  
    }
    
    void push(int val) {
        this->minimum=min(this->minimum,val);
        pair<int,int> p;
        p.first=val;
        p.second=this->minimum;
        ans.push_back(p);
    }
    
    void pop() {
        pair<int,int> p=ans[ans.size()-1];
        ans.pop_back();
        if(ans.size() == 0)
        {
            this->minimum=INT_MAX;
            return;
        }
        if(p.second == this->minimum)
        {
            this->minimum=ans[ans.size()-1].second;
            return;
        }
    }
    
    int top() {
        return ans[ans.size()-1].first;
    }
    
    int getMin() {
        return ans[ans.size()-1].second;
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