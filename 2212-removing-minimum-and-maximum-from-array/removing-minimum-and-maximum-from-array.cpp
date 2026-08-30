class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int mini_count = -1,mini = INT_MAX;
        int max_count = -1,maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < mini){
                mini = nums[i];
                mini_count = i;
            }
            if(nums[i] > maxi){
                maxi = nums[i];
                max_count = i;
            }
        }
        bool back1 = false,back2 = false;
        int lower,upper;
        if(mini_count +1 < nums.size()-mini_count){
            lower = mini_count+1;
        }
        else{
            lower = nums.size()-mini_count;
            back1 = true;
        }
        if(max_count +1 < nums.size() - max_count) upper = max_count+1;
        else{
            upper = nums.size() - max_count;
            back2 = true;
        }
        if(back1 == back2) return max(upper,lower);
        else if(abs(max_count - mini_count) < upper || abs(max_count - mini_count)<lower){
            return abs(mini_count - max_count) + min(upper,lower);
        }
        return upper + lower;
    }
};