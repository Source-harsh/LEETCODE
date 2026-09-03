class Solution {
public:
    vector<string> letterCombinations(string digit) {
        unordered_map<int,vector<string>> mpp;
        mpp[2] = {"a","b","c"};
        mpp[3] = {"d","e","f"};
        mpp[4] = {"g","h","i"};
        mpp[5] = {"j","k","l"};
        mpp[6] = {"m","n","o"};
        mpp[7] = {"p","q","r","s"};
        mpp[8] = {"t","u","v"};
        mpp[9] = {"w","x","y","z"};
        vector<string> ans;
        if(digit.size() == 0) return {};
        if(digit.size() == 1) return mpp[stoi(digit)];
        else if(digit.size() == 2){
            for(string ch : mpp[digit[0] - '0']){
                string ss = ch;
                for(string hc : mpp[digit[1] - '0']){
                    ss += hc;
                    ans.push_back(ss);
                    ss.pop_back();
                }
                ss.pop_back();
            }
        }
        else if(digit.size() == 3){
            for(string ch : mpp[digit[0] - '0']){
                string ss = ch;
                for(string hc : mpp[digit[1]-'0']){
                    ss += hc;
                    for(string dc : mpp[digit[2]-'0']){
                        ss += dc;
                        ans.push_back(ss);
                        ss.pop_back();
                    }
                    ss.pop_back();
                }
                ss.pop_back();
            }
        }
        else{
            for(string ch : mpp[digit[0] - '0']){
                string ss = ch;
                for(string hc : mpp[digit[1]-'0']){
                    ss += hc;
                    for(string dc : mpp[digit[2]-'0']){
                        ss += dc;
                        for(string cd : mpp[digit[3]-'0']){
                            ss += cd;
                            ans.push_back(ss);
                            ss.pop_back();
                        }
                        ss.pop_back();
                    }
                    ss.pop_back();
                }
                ss.pop_back();
            }
        }
        return ans;
    }
};