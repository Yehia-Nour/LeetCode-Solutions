class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> vec;
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                    greater<pair<int, int>>> min_heap;
        int num_of_soldiers;

        for (int i = 0; i < mat.size(); ++i) {
            num_of_soldiers = 1;
            for (int j = 1; j < mat[i].size(); ++j)
                if (mat[i][j] == 1) ++num_of_soldiers;
            min_heap.push({num_of_soldiers, i});
        }

        for (int i = 0; i < k; ++i) {
            vec.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return vec;
    }
};