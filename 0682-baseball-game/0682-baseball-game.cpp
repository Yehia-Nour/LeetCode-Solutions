class Solution {
public:
    static int calPoints(vector<string>& operations) {
        vector<int> stack;
        for(string& s: operations){
            char c=s[0];
            switch(c){
                case '+': stack.push_back(stack.back()+(*(stack.end()-2))); break;
                case 'D': stack.push_back(stack.back()*2); break;
                case 'C': stack.pop_back(); break;
                default: stack.push_back(stoi(s));
            }
        }
        return accumulate(stack.begin(), stack.end(), 0);
    }
};