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
    void solve(unordered_map<int, pair<int, int>>& map, TreeNode* root) {
        if (map.find(root->val) == map.end())
            return;

        if (map[root->val].first) {
            TreeNode* left = new TreeNode(map[root->val].first);
            root->left = left;
            solve(map, left);
        }

        if (map[root->val].second) {
            TreeNode* right = new TreeNode(map[root->val].second);
            root->right = right;
            solve(map, right);
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        //  sort(descriptions.begin() , descriptions.end());

        unordered_set<int> set;
        unordered_map<int, pair<int, int>> map;
        // put all parent in set
        for (int i = 0; i < descriptions.size(); i++) {
            set.insert(descriptions[i][0]);
            int flag = descriptions[i][2];
            if (flag == 1) {
                map[descriptions[i][0]].first = descriptions[i][1];
            } else {
                map[descriptions[i][0]].second = descriptions[i][1];
            }
        }
        // check if parent in child of anthor node remove from set

        for (int i = 0; i < descriptions.size(); i++) {

            if (set.find(descriptions[i][1]) != set.end()) {
                set.erase(descriptions[i][1]);
            }
        }

        auto itr1 = set.begin();
        TreeNode* root = new TreeNode(*itr1);
        solve(map, root);
        return root;
    }
};