class Solution {
public:
    long long minCost(vector<int>& nums) {
        long long ans = LLONG_MAX;
        int length = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]) length++;
            else{
                long long temp = LLONG_MAX;
                if(i != 1)temp = nums[i-1]*(nums.size()-length);
                ans = min(ans,temp);
                length = 1;
            }
        }
        if(length != 1){
            long long temp = nums[nums.size()-1]*(nums.size()-length);
            ans = min(temp,ans);
        }
        return ans;

    }
};