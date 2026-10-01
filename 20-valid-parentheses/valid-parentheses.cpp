class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' ||s[i] =='{' || s[i] == '[') st.push(s[i]);
            else{
                if(st.empty()) return false;
                char ss = st.top();
                if(s[i] == ')'){
                    if(ss == '(' && st.empty() == false) st.pop();
                    else return false;
                }
                else if(s[i] == '}'){
                    if(ss == '{' && st.empty() == false) st.pop();
                    else return false;
                }
                else if(s[i] == ']'){
                    if(ss == '[' && st.empty() == false) st.pop();
                    else return false;
                }
            }
        }
        return st.size() == 0?true:false;
    }
};