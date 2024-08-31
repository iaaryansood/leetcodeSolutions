class MedianFinder {
public:
    priority_queue<int> maxheap;    //maxheap for smaller elements
    priority_queue<int,vector<int>,greater<int>> minheap;       //minheap for maximum elements
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || num <= maxheap.top())
        {
            maxheap.push(num);
        }
        else
        {
            minheap.push(num);
        }

        // balance out the heaps to ensure the maxheap contains only one extra element than the minheap in case of odd numbers and same numbers for even numbers
        if(maxheap.size() > minheap.size() + 1)
        {
            int ele=maxheap.top();
            minheap.push(ele);
            maxheap.pop();
        }
        else if(minheap.size() > maxheap.size())
        {
            int ele=minheap.top();
            maxheap.push(ele);
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.size() > minheap.size())
        {
            return maxheap.top();
        }
        else
        {
            double temp;
            temp=(maxheap.top() + minheap.top()) * 0.5;
            return temp;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */