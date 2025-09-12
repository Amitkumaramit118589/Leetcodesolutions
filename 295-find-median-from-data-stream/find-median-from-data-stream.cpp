class MedianFinder {
public:
    priority_queue<int> left_maxheap; // max-heap (left half)
    priority_queue<int, vector<int>, greater<int>> right_minheap; // min-heap (right half)

    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Insert into correct heap
        if (left_maxheap.empty() || num <= left_maxheap.top()) {
            left_maxheap.push(num);
        } else {
            right_minheap.push(num);
        }

        // Step 2: Balance both heaps
        if (left_maxheap.size() > right_minheap.size() + 1) {
            right_minheap.push(left_maxheap.top());
            left_maxheap.pop();
        } else if (right_minheap.size() > left_maxheap.size()) {
            left_maxheap.push(right_minheap.top());
            right_minheap.pop();
        }
    }

    double findMedian() {
        if (left_maxheap.size() > right_minheap.size()) {
            return left_maxheap.top();
        } else {
            return (left_maxheap.top() + right_minheap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */