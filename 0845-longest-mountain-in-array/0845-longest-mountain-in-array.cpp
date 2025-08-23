vector<int> arr;
const int MAX = 10000 + 1;
int memoUp[MAX];
int memoDown[MAX];

int getUp(int i) {
    if (memoUp[i] != -1) return memoUp[i];
    if (i == 0 || arr[i] <= arr[i-1]) return memoUp[i] = 1;
    return memoUp[i] = 1 + getUp(i-1);
}

int getDown(int i) {
    if (memoDown[i] != -1) return memoDown[i];
    if (i == (int)arr.size() - 1 || arr[i] <= arr[i+1]) return memoDown[i] = 1;
    return memoDown[i] = 1 + getDown(i+1);
}

class Solution {
public:
    int longestMountain(vector<int>& input) {
        arr = input;
        int n = arr.size();
        memset(memoUp, -1, sizeof(memoUp));
        memset(memoDown, -1, sizeof(memoDown));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int up = getUp(i);
            int down = getDown(i);
            if (up > 1 && down > 1)  
                ans = max(ans, up + down - 1);
        }
        return ans;
    }
};