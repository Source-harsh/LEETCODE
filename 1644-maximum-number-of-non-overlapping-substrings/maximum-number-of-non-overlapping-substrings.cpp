class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        vector<pair<int,int>> loc(26, {-1,-1});

        // first and last occurrence
        for(int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if(loc[c].first == -1)
                loc[c].first = i;

            loc[c].second = i;
        }

        vector<pair<int,int>> valid;

        // Try every character as starting point
        for(int i = 0; i < 26; i++) {

            if(loc[i].first == -1)
                continue;

            int start = loc[i].first;
            int end = loc[i].second;

            bool ok = true;

            // Scan actual string characters
            for(int j = start; j <= end; j++) {

                int c = s[j] - 'a';

                // Character occurs before our start
                if(loc[c].first < start) {
                    ok = false;
                    break;
                }

                // Must include all occurrences
                end = max(end, loc[c].second);
            }

            if(ok) {
                valid.push_back({start, end});
            }
        }

        // Sort by ending position
        sort(valid.begin(), valid.end(),
            [](auto &a, auto &b) {
                return a.second < b.second;
            });

        vector<string> ans;

        int prevEnd = -1;

        for(auto [start, end] : valid) {

            if(start > prevEnd) {
                ans.push_back(
                    s.substr(start, end - start + 1)
                );

                prevEnd = end;
            }
        }

        return ans;
    }
};