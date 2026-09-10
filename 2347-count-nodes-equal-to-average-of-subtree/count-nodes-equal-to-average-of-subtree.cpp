/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int ans = 0;

    pair<int,int> dfs(TreeNode* root){
        if(root->left == NULL && root->right ==  NULL){
            ans++;
            return {root->val,1};
        }
        pair<int,int> leftsum = {0,0},rightsum = {0,0};
        if(root->left != NULL) leftsum = dfs(root->left);
        if(root->right != NULL) rightsum = dfs(root->right);
        if((root->val +leftsum.first + rightsum.first)/(leftsum.second + rightsum.second +1) == root->val){
            ans++;
        }
        return {leftsum.first+rightsum.first+root->val,1+leftsum.second + rightsum.second};
    }

    int averageOfSubtree(TreeNode* root) {
        pair<int,int> prr = dfs(root);
        return ans;
    }
};