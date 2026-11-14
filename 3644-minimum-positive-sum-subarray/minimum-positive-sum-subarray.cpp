class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int answer = INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j=i;j<min(i+r,(int)nums.size());j++){
                sum += nums[j];
                if(j-i+1 >=l && sum >0 && sum < answer){
                    answer = sum;
                }
            }
        }
        return answer == INT_MAX?-1:answer;
    }
};