class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;

        // Left -> Right
        int open = 0, close = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close) {
                ans = max(ans, 2 * close);
            }
            else if (close > open) {
                // This ')' can never be part of a valid substring
                open = close = 0;
            }
        }

        // Right -> Left
        open = close = 0;

        for (int i = s.size() - 1; i >= 0; i--) {

            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close) {
                ans = max(ans, 2 * open);
            }
            else if (open > close) {
                // This '(' can never be part of a valid substring
                open = close = 0;
            }
        }

        return ans;
    }
};