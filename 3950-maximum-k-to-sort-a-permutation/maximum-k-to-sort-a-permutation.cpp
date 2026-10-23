class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> lol = nums;
        sort(lol.begin(),lol.end());
        int k = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != lol[i]){
                k &= nums[i];
            }
        }
        return k == -1?0:k;
    }
};