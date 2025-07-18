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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) { st.push(root); }

    int next() {
        if (st.empty())
            return -1;
        TreeNode* cur = st.top() ; 
        if(!cur->left && !cur->right) 
        {
            st.pop() ;
            return cur->val ;
        }
        if(cur->left)
        {
           
            // if(cur->left->right)
            // {
            //     st.push(cur->left->right) ; 
            // }
             st.push(cur->left) ; 
            // if(cur->left->left)
            // {
            //     st.push(cur->left->left);
            // }

            int v = cur->left->val ;
            cur->left = nullptr ; 
            return next() ;
        }

        st.pop() ; 
        if(cur->right)
        {
            st.push(cur->right) ;
            cur->right = nullptr ;  
        }

        return cur->val ; 
        
    }

    bool hasNext() { return st.size(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */