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
    
    int solve(TreeNode * node , bool &isBalanced)
    {

        if(!node) return 0 ; 

        int left = solve(node->left , isBalanced) ; 
        int right = solve(node->right ,isBalanced) ;

        if(abs(left - right) >1) isBalanced = false;
        return max(left , right)+1 ; 
    }
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true ; 
        solve(root , isBalanced) ; 
        return isBalanced ; 
    }
};