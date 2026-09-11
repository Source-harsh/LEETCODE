class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};

        for (int d : digits)
            freq[d]++;

        int ans = 0;

        // Choose hundreds digit
        for (int h = 1; h <= 9; h++) {

            if (freq[h] == 0)
                continue;

            // Choose units digit (must be even)
            for (int e = 0; e <= 8; e += 2) {

                if (freq[e] == 0)
                    continue;

                // If h == e, we need at least 2 copies
                if (h == e && freq[h] < 2)
                    continue;

                int tens = 0;

                // Count distinct digits available for tens position
                for (int t = 0; t <= 9; t++) {

                    int remaining = freq[t];

                    // One copy used by hundreds
                    if (t == h)
                        remaining--;

                    // One copy used by units
                    if (t == e)
                        remaining--;

                    if (remaining > 0)
                        tens++;
                }

                ans += tens;
            }
        }

        return ans;
    }
};