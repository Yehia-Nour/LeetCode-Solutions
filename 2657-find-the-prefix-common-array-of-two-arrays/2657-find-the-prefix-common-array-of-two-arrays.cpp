class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_map<int, int> map;

        for (int i = 0; i < A.size(); i++) {
            map[A[i]]++;
            map[B[i]]++;

            int count = 0;

            for (auto pair : map) {
                count += pair.second - 1;
            }

            res.push_back(count);
        }

        return res;
    }
};