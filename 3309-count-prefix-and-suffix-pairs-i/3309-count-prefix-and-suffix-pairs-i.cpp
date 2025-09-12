
class TrieNode {
    public:
    TrieNode* childern[26];
    TrieNode* back[26];
    int val;
    int counter ; 
    bool isend;
    TrieNode(int _val) {
        val = _val;
        counter=0 ; 
        isend = false;
        for (int i = 0; i < 26; i++) {
            childern[i] = nullptr;
        }
      
    }
    TrieNode() {}
};

class Trie {
    public:
    TrieNode* root;
    int ans;
    Trie() {
        root = new TrieNode(-1);
        ans = 0;
    }

    void insert(string &s) {
        TrieNode* cur = root;
       
        int end = s.size() - 1;
       string d = "";
        for (int i = 0; i < s.size(); i++) {
            d+=s[i];
            if (cur->childern[s[i] - 'a']  && cur->childern[s[i] - 'a']->isend) {
             
                ans +=  (s.substr(s.size() - d.size() , d.size())== d ) ?  cur->childern[s[i] - 'a']->counter  : 0; 
            }
            if (!cur->childern[s[i] - 'a']) {
                cur->childern[s[i] - 'a'] = new TrieNode(s[i] - 'a' );
            }
            

            cur = cur->childern[s[i] - 'a'];
        }
        cur->isend = true;
        cur->counter++ ; 
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {

       Trie *trie = new Trie();
        for(int i =0 ; i<words.size() ; i++)
        {
            trie->insert(words[i]);
        }
        return trie->ans ;
    }
};