class Solution {
public:
    class TrieNode {
    public:
        TrieNode* child[2];
        TrieNode() {
            child[0] = nullptr;
            child[1] = nullptr;
        }
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() { root = new TrieNode(); }

        void insert(int num) {
            TrieNode* node = root;
            for (int i = 30; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (!node->child[bit]) {
                    node->child[bit] = new TrieNode();
                }
                node = node->child[bit];
            }
        }

        int getMaxXor(int num) {
            TrieNode* node = root;
            int maxXor = 0;
            for (int i = 30; i >= 0; i--) {
                int bit = (num >> i) & 1;
                int opposite = 1 - bit;
                if (node->child[opposite]) {
                    maxXor |= (1 << i);
                    node = node->child[opposite];
                } else {
                    node = node->child[bit];
                }
            }
            return maxXor;
        }
    };

    int findMaximumXOR(vector<int>& nums) {

        int ans = 0;
        Trie trie;
        for (int num : nums) {
            trie.insert(num);
        }

        for (int num : nums) {
            ans = max(ans, trie.getMaxXor(num));
        }
        return ans;
    }
};