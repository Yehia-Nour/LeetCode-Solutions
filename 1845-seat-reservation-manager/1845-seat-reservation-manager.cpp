class SeatManager {
    priority_queue<int, vector<int>, greater<int>> min;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            min.push(i);
        }
    }
    
    int reserve() {
        int re = min.top();
        min.pop();
        return re;
    }
    
    void unreserve(int seatNumber) {
        min.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */