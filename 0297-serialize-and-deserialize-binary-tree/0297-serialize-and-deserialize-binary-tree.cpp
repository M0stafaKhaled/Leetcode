/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

void dfs(TreeNode* node, string& res) {
    if (!node) {
        res += "null,";
        return;
    }

    res += to_string(node->val) + ",";
    dfs(node->left, res);
    dfs(node->right, res);
}

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "" ; 
        string res  ="";
        dfs(root , res) ; 

        return res ; 
    }
    TreeNode* build(vector<int>& arr, int& i)
    {
        if(arr[i] == -2000)
        {
            return nullptr ; 
        }
        TreeNode * cur = new TreeNode(arr[i]) ; 
        cur->left = build(arr , ++i) ; 
        cur->right = build(arr , ++i) ; 

        return cur ; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() ==0) return nullptr ; 
         
         vector<int>arr ; 
        for(int i =0 ; i<data.size() ; i++)
        {
            string root = "" ; 
            while(i<data.size() && data[i] != ',')
            {
                root+=data[i] ; 
                i++;
            }
            if(root == "null")
            {
                arr.push_back(-2000);
            }
            else arr.push_back(stoi(root)) ; 

        }
        int j =0 ; 
        TreeNode * cur  =  build(arr , j) ;
        
        return  cur ; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));