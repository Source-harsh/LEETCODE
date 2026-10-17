class Solution {
public:
    int ss(int a) {
        int sum = 0;
        while (a > 0) {
            sum += a % 10;
            a /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        vector<int> tt = nums;

        sort(nums.begin(), nums.end(), [this](int a, int b) {
            if (ss(a) == ss(b)) return a < b;
            return ss(a) < ss(b);
        });

        int n = nums.size();
        vector<int> pos(n);


        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[nums[i]] = i;

        for (int i = 0; i < n; i++)
            pos[i] = mp[tt[i]];

        vector<bool> vis(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int j = i, cycle = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = pos[j];
                cycle++;
            }

            if (cycle > 1)
                count += cycle - 1;
        }

        return count;
    }
};