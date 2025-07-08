class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        auto isValidCode = [](const string& str) {
            if (str.empty()) return false;
            for (char ch : str) {
                if (!isalnum(ch) && ch != '_') return false;
            }
            return true;
        };

        vector<tuple<int, string>> valid;

        for (int i = 0; i < code.size(); ++i) {
            if (isValidCode(code[i]) &&
                order.find(businessLine[i]) != order.end() &&
                isActive[i]) {
                valid.emplace_back(order[businessLine[i]], code[i]);
            }
        }

        sort(valid.begin(), valid.end(), [](const auto& a, const auto& b) {
            if (get<0>(a) != get<0>(b))
                return get<0>(a) < get<0>(b);
            return get<1>(a) < get<1>(b);
        });

        vector<string> result;
        for (const auto& [_, c] : valid) {
            result.push_back(c);
        }

        return result;
    }
};
