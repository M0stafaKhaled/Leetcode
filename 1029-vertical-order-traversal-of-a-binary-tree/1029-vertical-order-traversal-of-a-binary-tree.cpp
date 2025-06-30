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
    void solve(TreeNode* root, int x, int y,
               map<int, vector<pair<int, int>>>& maps) {
        if (!root)
            return;
        maps[y].push_back({x, root->val});
        solve(root->left, x + 1, y - 1, maps);

        solve(root->right, x + 1, y + 1, maps);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<pair<int, int>>> maps;
        solve(root, 0, 0, maps);
        for (auto [x, n] : maps) {
            sort(n.begin(), n.end());
            vector<int> t(n.size());
            for (int j = 0; j < n.size(); j++) {
                t[j] = n[j].second;
            }
            ans.push_back(t);
        }
        return ans;
    }
};