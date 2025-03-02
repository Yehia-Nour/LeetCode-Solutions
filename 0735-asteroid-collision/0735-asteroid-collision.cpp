class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int> stc;

        for (int i = 0; i < asteroids.size(); ++i) {
            while (!stc.empty() && stc.top() > 0 && asteroids[i] < 0) {
                if (abs(stc.top()) < abs(asteroids[i])) {
                    stc.pop();
                } else if (abs(stc.top()) == abs(asteroids[i])) {
                    stc.pop();
                    asteroids[i] = 0;
                } else {
                    asteroids[i] = 0;  
                }
            }

            if (asteroids[i] != 0) {
                stc.push(asteroids[i]);
            }
        }

        vector<int> result(stc.size());
        for (int i = stc.size() - 1; i >= 0; --i) {
            result[i] = stc.top();
            stc.pop();
        }

        return result;
    }
};