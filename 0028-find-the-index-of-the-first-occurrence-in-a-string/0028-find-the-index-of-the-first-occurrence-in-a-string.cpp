class Solution {
public:
    vector<int> build(const string pat) {
        vector<int> arr(pat.size());
        int index = 0;
        arr[index] = 0;
        for (int i = 1; i < pat.size();) {
            if (pat[i] == pat[index]) {
                index++;
                arr[i] = index;
                i++;

            } else {
                if (index != 0) {
                    index = arr[index - 1];
                } else {
                    arr[i] = 0;
                    i++;
                }
            }
        }

        return arr;
    }
    int strStr(string haystack, string needle) {

        vector<int> arr = build(needle);

        int j = 0;
        for (int i = 0; i < haystack.size();) {

            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == needle.size()) {
                return i - (needle.size());
            }

            if (i < haystack.size() && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = arr[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }
};