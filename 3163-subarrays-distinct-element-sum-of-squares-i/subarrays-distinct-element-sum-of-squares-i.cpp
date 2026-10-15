class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        set<int> st;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                st.insert(nums[j]);
                ans += (st.size()*st.size());
            }
            st.clear();
        }
        return ans;
    }
};