class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')' && st.empty() == false){
                st.pop();
            }
            ans = max(ans,(int)st.size());
        }
        return ans;
    }
};