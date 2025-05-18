class SmallestInfiniteSet {
private:
    int cur;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::unordered_set<int> inHeap;

public:
    SmallestInfiniteSet() {
        cur = 1;
    }

    int popSmallest() {
        if (!minHeap.empty()) {
            int smallest = minHeap.top();
            minHeap.pop();
            inHeap.erase(smallest);
            return smallest;
        }
        return cur++;
    }

    void addBack(int num) {
        if (num < cur && inHeap.count(num) == 0) {
            minHeap.push(num);
            inHeap.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */