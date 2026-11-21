
class Solution {
public:
    void dfs(int node, vector<vector<int>>& children,
             vector<vector<int>>& occ, vector<int>& parent, string& s) {

        int ch = s[node] - 'a';

        if (!occ[ch].empty()) {
            parent[node] = occ[ch].back();
        }

        occ[ch].push_back(node);

        for (int i = 0; i < children[node].size(); i++) {
            dfs(children[node][i], children, occ, parent, s);
        }

        occ[ch].pop_back();
    }

    void getSubtreeSize(int node, vector<vector<int>>& children,
                        vector<int>& ans) {

        ans[node] = 1;

        for (int i = 0; i < children[node].size(); i++) {
            int child = children[node][i];

            getSubtreeSize(child, children, ans);

            ans[node] += ans[child];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        vector<vector<int>> occ(26);

        dfs(0, children, occ, parent, s);

        vector<vector<int>> newChildren(n);

        for (int i = 1; i < n; i++) {
            newChildren[parent[i]].push_back(i);
        }

        vector<int> ans(n, 0);

        getSubtreeSize(0, newChildren, ans);

        return ans;
    }
};
