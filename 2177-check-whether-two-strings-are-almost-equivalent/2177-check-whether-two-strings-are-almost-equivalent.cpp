class Solution {
public:
    int arr[26];
    int arr2[26];
    bool checkAlmostEquivalent(string word1, string word2) {

        for (int i = 0; i < word1.size(); i++) {
            arr[word1[i] - 'a']++;
            arr2[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (abs(arr[i] - arr2[i]) > 3)
                return 0;
        }

        return 1;
    }
};