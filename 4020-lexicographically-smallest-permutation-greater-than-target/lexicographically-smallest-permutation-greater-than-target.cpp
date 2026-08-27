class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        string ans = "";

        // prefix that matches target
        string prefix = "";

        for (int i = 0; i < n; i++) {

            // Try making position i the first greater position
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (freq[c] == 0)
                    continue;

                string candidate = prefix;
                candidate += char('a' + c);

                // Use this character
                freq[c]--;

                // Add remaining characters in sorted order
                for (int k = 0; k < 26; k++) {
                    candidate += string(freq[k], 'a' + k);
                }

                if (ans.empty() || candidate < ans)
                    ans = candidate;

                // Restore
                freq[c]++;
            }

            // Continue matching target[i]
            int c = target[i] - 'a';

            if (freq[c] == 0)
                break;

            prefix += target[i];
            freq[c]--;
        }

        return ans;
    }
};