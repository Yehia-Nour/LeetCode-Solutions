class Solution {
public:
    string makeGood(string s) {
        string str = "";
        if(s.length() == 0) return str;

        stack<char> st;
        for(char ch : s)
        {
            if(st.empty())
            {
                st.push(ch);
            }
            else if(isupper(st.top()))
            {
                if(ch == tolower(st.top())) st.pop();
                else st.push(ch);
            }
            else
            {
                if(ch == toupper(st.top())) st.pop();
                else st.push(ch);
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