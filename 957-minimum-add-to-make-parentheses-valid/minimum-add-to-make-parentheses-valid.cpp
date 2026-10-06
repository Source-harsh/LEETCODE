class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int balance = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == ')'){
                balance--;
                if(balance <0){
                    ans += abs(balance);
                    balance = 0;
                }
            }
            else if(s[i] == '('){
                balance++;
            }
        }
        return ans + balance;
    }
};