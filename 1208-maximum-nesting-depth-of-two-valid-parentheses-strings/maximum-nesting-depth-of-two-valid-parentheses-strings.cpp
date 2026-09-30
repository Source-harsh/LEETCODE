class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<char> st;
        vector<int> ans(seq.size(),0);
        for(int i=0;i<seq.size();i++){
            if(seq[i] == '('){
                if(st.size()%2 != 0){
                    ans[i] = 1;
                }
                st.push('(');
            }
            else if(seq[i] == ')' && st.empty() == false){
                st.pop();
                if(st.size()%2 != 0){
                    ans[i] = 1;
                }
            }
        }
        return ans;

    }
};