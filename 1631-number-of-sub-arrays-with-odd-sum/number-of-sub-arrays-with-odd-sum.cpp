class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<long long> prefix(arr.size(),0);
        prefix[0] = arr[0];
        for(int i=1;i<arr.size();i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
        int odd =0,even =0;
        int ans = 0;
        int modulo = 1e9 +7;
        for(int i=0;i<prefix.size();i++){
            if(prefix[i]%2 == 1) ans = (ans+1)%modulo;
            prefix[i]%2 == 0?ans = (ans+odd)%modulo: ans = (ans + even)%modulo;
            prefix[i]%2 == 0?even++:odd++;
        }
        return ans;
    }
};