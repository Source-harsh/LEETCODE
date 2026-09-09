class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string shortest = "";
        for(string st : strs){
            if(shortest.size() == 0) shortest = st;
            shortest.size() > st.size()?shortest = st:shortest = shortest;
        }
        string ans = "";
        for(int i=0;i<shortest.size();i++){
            bool flag = false;
            for(string st : strs){
                if(shortest[i] != st[i]){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            ans += shortest[i];
        }
        return ans;
    }
};