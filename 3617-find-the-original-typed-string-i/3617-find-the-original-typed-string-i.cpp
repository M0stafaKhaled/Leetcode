class Solution {
public:
    int possibleStringCount(string word) {

        int ans = 1;
        for (int i = 0; i < word.size(); i++) {

            while(i+1<word.size() &&  word[i] == word[i+1]) ans++ , i++;
        }

        return ans;
    }
};