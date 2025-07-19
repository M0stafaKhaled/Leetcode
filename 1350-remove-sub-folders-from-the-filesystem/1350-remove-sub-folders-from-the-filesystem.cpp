class TrieNode
{
    public:
    unordered_map<char , TrieNode*> childern;
    bool isend ;

    TrieNode()
    {
    
        isend=false;
    }

};
class Trie
{
    public:
    TrieNode * root ; 
    Trie()
    {
        root= new TrieNode(); 
    }

    void insert(string word)
    {
        TrieNode * node = root ; 
        for(auto e : word)
        {
            if(!node->childern[e])
            {
                node->childern[e] = new TrieNode();
            }
            node = node->childern[e];
        }
        node->childern['/'] = new TrieNode();
        node =   node->childern['/'];
        node->isend= true ; 
    }

    bool isprefix(string word)
    {
        TrieNode * node = root ; 
        int counter =0 ;
        for(auto e : word)
        {
           
            if(!node->childern[e])
            {
                return false;
            }
            if(node->childern[e]->isend) return true;
            node = node->childern[e];
          
        }
        return false ;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        Trie *trie = new Trie();
        for(string d :folder)
        {
             trie->insert(d);
        }
        vector<string> ans ; 
        for(string d :folder)
        {
            if(!trie->isprefix(d))
            {
                ans.push_back(d);
            }
        }
        return ans ; 
    }
};