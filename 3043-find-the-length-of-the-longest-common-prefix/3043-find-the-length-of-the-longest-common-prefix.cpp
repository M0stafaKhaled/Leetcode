class TrieNode{
    public :
    TrieNode * childern[10];
    TrieNode()
    {
        for(int i =0 ; i<=9 ; i++)
        {
            childern[i] = nullptr ; 
        }

    }
};

class Trie {
    public:
    TrieNode * root ; 
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *cur =root ; 
        for(auto c : word)
        {
            if(cur->childern[c-'0'] == nullptr)
            {
                cur->childern[c - '0'] = new TrieNode();
            }
            cur = cur->childern[c-'0'];
        }
    }
    bool isprefix(string word)
    {
          TrieNode *cur =root ; 
        for(auto c : word)
        {
            if(cur->childern[c-'0'] == nullptr)
            {
                return false; 
            }
            cur = cur->childern[c-'0'];
        }
        return true ; 
    }
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        Trie trie ;
        for(int i =0 ; i<arr2.size() ; i++)
        {
                trie.insert(to_string(arr2[i]));
        }
        int ans =0 ; 
        for(int i =0 ; i<arr1.size() ; i++)
        {
            string temp = to_string(arr1[i]);
            string m = "" ; 
            for(int i =0 ; i<temp.size() ; i++)
            {
                m+=temp[i] ; 
                if(trie.isprefix(m))
                {
                    ans = max(ans , i+1);
                }
            }
        }
        return ans ; 
    }
};