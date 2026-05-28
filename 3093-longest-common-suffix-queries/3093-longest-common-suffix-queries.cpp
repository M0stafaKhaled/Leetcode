class Solution {
public:
    struct Node {
        int child[26];
        int bestIdx;

        Node() {
            memset(child, -1, sizeof(child));
            bestIdx = -1;
        }
    };

    vector<Node> trie;
    vector<string>* words;

    bool better(int a, int b) {
        if (b == -1)
            return true;

        int lenA = (*words)[a].size();
        int lenB = (*words)[b].size();

        if (lenA != lenB)
            return lenA < lenB;
        return a < b;
    }

    void updateBest(int node, int idx) {
        if (better(idx, trie[node].bestIdx)) {
            trie[node].bestIdx = idx;
        }
    }

    void insert(string& s, int idx) {
        int node = 0;
        updateBest(node, idx);

        for (int i = s.size() - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[c];
            updateBest(node, idx);
        }
    }

    int search(string& q) {
        int node = 0;

        for (int i = q.size() - 1; i >= 0; i--) {
            int c = q[i] - 'a';

            if (trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].bestIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        words = &wordsContainer;

        trie.reserve(wordsContainer.size() + 1);
        trie.push_back(Node());

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (auto& q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};