class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int ans = 0;
        if(nums.size() == 1) return 1;
        for(int i=0;i<nums.size();i++){
            if(i == 0){
                if(nums[i] >= nums[i+1]) ans++;
            }
            else if(i == nums.size()-1){
                if(nums[i] >= nums[i-1]) ans++;
            }
            else{
                int avgg = nums[i-1] + nums[i+1];
                avgg%2 == 0?avgg +=0 :avgg +=1;
                if(nums[i] >= (avgg/2)) ans++;
            }
        }
        return ans;
    }
};