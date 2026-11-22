class Solution {
public:
    bool checkString(string s) {
        bool b_ap = false;
        bool ans = true;
        for(char ch : s){
            if(ch == 'a' && b_ap == true) ans = false;
            else if(ch == 'b') b_ap = true;
        }
        return ans;
    }
};