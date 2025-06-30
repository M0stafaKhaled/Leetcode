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
    unordered_map<int  , vector<pair<int , int>>>map ; 
    void solve(TreeNode * root , int x , int y )
    {
        if(!root) return ; 
        map[y].push_back({x , root->val}) ; 

        solve(root->left ,x+1 ,  y -1) ; 

        solve(root->right ,x+1 ,  y+1) ; 
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<vector<int>> ans ;
         solve(root , 0 ,0) ;  
        for(int i =-1000 ;i<=1000 ; i++)
        {
            if(map[i].size())
            {
                sort(map[i].begin() , map[i].end());
                vector<int> t(map[i].size()) ; 
                for(int j =0 ; j<map[i].size() ; j++)
                {
                    t[j]= map[i][j].second ; 
                }
                ans.push_back(t);
            }
        }
        return ans ; 
    }
};