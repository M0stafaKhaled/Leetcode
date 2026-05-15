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
    vector<TreeNode*> solve(int left, int right) {

        if (left == right) {
            return {new TreeNode(left)};
        }

        vector<TreeNode*> res;
        if (left > right)
            return {nullptr};

        for (int i = left; i <= right; i++) {
            for (auto LeftTree : solve(left, i - 1)) {
                for (auto rightTree : solve(i + 1, right)) {
                    TreeNode* root = new TreeNode(i, LeftTree, rightTree);
                    res.push_back(root);
                }
            }
        }

        return res;
    }
    vector<TreeNode*> generateTrees(int n) { return solve(1, n); }
};