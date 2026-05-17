/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<string> ans;

    void solve(TreeNode* root, string path) {
        if (!root)
            return;

        if (!root->left && !root->right) {
            path += to_string(root->val);
            ans.push_back(path);
            return;
        }

        path += to_string(root->val);
        ;
        path += "->";
        solve(root->left, path);
        solve(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root, "");

        return ans;
    }
};