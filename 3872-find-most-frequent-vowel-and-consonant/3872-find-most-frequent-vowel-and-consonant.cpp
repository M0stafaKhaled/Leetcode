class Solution {
public:
    int arr[26];
    int maxFreqSum(string s) {

        // int a , e , i , o , u ;
        // a = e = i = o = u = 0 ;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
            }

            arr[s[i] - 'a']++;
        }

        int a1 = 0;
        int a2 = 0;

        for (int i = 0; i < 26; i++) {
            char e = i + 'a';
            if (e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u') {

                a1 = max(a1, arr[i]);
            } else {
                a2 = max(a2, arr[i]);
            }
        }

        // if (!a1 || !a2)
        //     return 0;

        return a1 + a2;
    }
};