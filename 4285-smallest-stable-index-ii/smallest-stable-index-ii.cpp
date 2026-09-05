class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans =-1;
        vector<int> maxi(nums.size(),0);
        vector<int> mini(nums.size(),0);
        maxi[0] = nums[0];
        mini[nums.size()-1] = nums[nums.size()-1];
        for(int i =1;i<nums.size();i++){
            maxi[i] = max(nums[i],maxi[i-1]);
            mini[nums.size()-i-1] = min(nums[nums.size()-1-i],mini[nums.size()-i]);
        }
        for(int i=0;i<nums.size();i++){
            if((maxi[i]-mini[i]) <= k){
                ans = i;
                break;
            }
        }
        return ans;
    }
};