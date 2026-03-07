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
    bool ans = true ; 
    int solve(TreeNode * node)
    {

        if(!node) return 0 ; 

        int left = solve(node->left) ; 
        int right = solve(node->right) ;

        if(abs(left - right) >1) ans = false;
        return max(left , right)+1 ; 
    }
    bool isBalanced(TreeNode* root) {
        ans = true ; 
        solve(root) ; 
        return ans ; 
    }
};