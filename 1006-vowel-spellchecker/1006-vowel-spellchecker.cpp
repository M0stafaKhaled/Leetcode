class Solution {
public:
    bool isVowel(char ch) {
        char c = tolower(ch);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string to_lower(string s) {
        string lower = s;
        for (auto& ch : lower) {
            ch = tolower(ch);
        }
        return lower;
    }

    string rep_vowel(string word) {
        string l = to_lower(word);
        for (auto& ch : l)
            if (isVowel(ch))
                ch = '.';
        return l;
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
       
        unordered_set<string> full(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap;
        unordered_map<string, string> ve;

        for (auto& word : wordlist) {
            string l = to_lower(word);
            if (!cap.count(l))
                cap[l] = word;

            string rep = rep_vowel(word);
            if (!ve.count(rep))
                ve[rep] = word;
        }

        vector<string> ans;
        for (auto& q : queries) {
            if (full.count(q)) {
                ans.push_back(q);
                continue;
            }
            string ql = to_lower(q);
            if (cap.count(ql)) {
                ans.push_back(cap[ql]);
                continue;
            }
            string qr = rep_vowel(q);
            if (ve.count(qr))
                ans.push_back(ve[qr]);
            else
                ans.push_back("");
        }
        return ans;
    }
};