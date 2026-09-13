class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> ones;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j] == 1) {
                    ones.push_back({i, j});
                }
            }
        }

        int ans = 0;
        for(int dr = -(n-1); dr <= n-1; dr++) {
            for(int dc = -(n-1); dc <= n-1; dc++) {

                int overlap = 0;
                for(auto [r, c] : ones) {

                    int nr = r + dr;
                    int nc = c + dc;
                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < n) {

                        if(img2[nr][nc] == 1) {
                            overlap++;
                        }
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};