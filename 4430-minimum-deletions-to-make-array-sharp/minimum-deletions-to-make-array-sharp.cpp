class Solution {
public:
    int minDeletions(vector<int>& nums) {
        vector<pair<int,int>> ans;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]) ans.push_back({i,i+1});
        }
        return ans.size();
    }
};