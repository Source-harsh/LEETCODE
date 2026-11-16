class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string tt = "";
            int sum =0;
            for(int i=0;i<s.size();i++){
                int l = s[i]-'0';
                sum += l;
                if((i+1)%k == 0){
                    tt += to_string(sum);
                    sum =0;
                }
            }
            if(s.size()%k != 0)tt += to_string(sum);
            s = tt;
        }
        return s;
    }
};