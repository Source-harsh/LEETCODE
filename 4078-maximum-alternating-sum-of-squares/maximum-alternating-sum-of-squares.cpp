class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        for(int i=0;i<nums.size();i++) nums[i] = abs(nums[i]);
        sort(nums.begin(),nums.end());
        int half;
        if(nums.size()%2 == 0){
            half = nums.size()/2 -1;
        }
        else{
            half = (nums.size()+1)/2 -2;
        }
        for(int i=0;i<nums.size();i++){
            i>half?ans +=(nums[i]*nums[i]):ans -=(nums[i]*nums[i]);
        }
        return ans;
    }
};