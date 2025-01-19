class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string str = "";
        for(char ch : s)
        {
            if(ch == '*')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
        while(!st.empty())
        {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};