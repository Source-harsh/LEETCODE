
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long> diff(nums1.size(), 0);

        for (int i = 0; i < nums1.size(); i++)
            diff[i] = abs((long long)nums1[i] - nums2[i]);

        map<long long, long long> mpp;

        for (int i = 0; i < nums1.size(); i++)
            mpp[diff[i]]++;

        long long total_opr = (long long)k1 + k2;

        while (total_opr > 0 && !mpp.empty()) {
            auto it = prev(mpp.end());

            long long number = it->first;
            long long ss = it->second;

            if (number == 0)
                break;

            if (total_opr >= ss) {
                mpp[number - 1] += ss;
                total_opr -= ss;
                mpp.erase(number);
            }
            else {
                mpp[number - 1] += total_opr;
                mpp[number] -= total_opr;
                total_opr = 0;
            }
        }

        long long ans = 0;

        for (auto it : mpp) {
            ans += it.first * it.first * it.second;
        }

        return ans;
    }
};
