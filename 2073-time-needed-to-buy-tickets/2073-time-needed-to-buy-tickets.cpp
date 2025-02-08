class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> queue;
        int time = 0;

        for(int i = 0; i < tickets.size(); i++) {
            queue.push(i);
        }

        while(!queue.empty()) {
            int index = queue.front();
            queue.pop();
            tickets[index]--;
            time++;

            if(tickets[index] == 0 && index == k) {
                return time;
            }
            if(tickets[index] > 0) {
                queue.push(index);
            }
        }
        return time;
    }
};