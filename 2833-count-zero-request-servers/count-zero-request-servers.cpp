class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        
        // Sort logs by time
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // Store {queryTime, originalIndex}
        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());
        vector<int> freq(n + 1, 0);

        int left = 0;
        int right = 0;
        int activeServers = 0;

        for (auto &[time, idx] : q) {

            // Add all logs with time <= query time
            while (right < logs.size() && logs[right][1] <= time) {
                int server = logs[right][0];

                if (freq[server] == 0)
                    activeServers++;

                freq[server]++;
                right++;
            }

            // Remove logs with time < time - x
            while (left < right && logs[left][1] < time - x) {
                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0)
                    activeServers--;

                left++;
            }

            // Servers with zero requests
            ans[idx] = n - activeServers;
        }

        return ans;
    }
};