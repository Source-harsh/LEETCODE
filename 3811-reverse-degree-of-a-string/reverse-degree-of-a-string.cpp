class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            int temp = s[i] - 'a';
            ans += (26-temp)*(i+1);
        }
        return ans;
    }
};