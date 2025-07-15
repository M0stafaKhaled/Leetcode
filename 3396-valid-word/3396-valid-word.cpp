class Solution {
public:
    bool isValid(string word) {

        int v = 0;
        int con = 0;
        int ch = 0;
        int n = 0;
        if(word.size() <3) return 0 ; 
        char arr[5] = {'a', 'e', 'i', 'o', 'u'};
        char arr2[5] = {'A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < word.size(); i++) {
            // A => 65 Z=> 90
            // a =>97 z=>122
            // 0=>48 => 57
            char x = word[i];
            if (x >= 65 && x <= 90) {
                ch++;
                bool f = false;
                for (int j = 0; j < 5; j++) {
                    if (x == arr2[j]) {
                        v++;
                        f = true;
                        break;
                    }
                }
                if (!f)
                    con++;
            } else if (x >= 97 && x <= 122) {
                ch++;
                bool f = false;
                for (int j = 0; j < 5; j++) {
                    if (x == arr[j]) {
                        v++;
                        f = true;
                        break;
                    }
                }
                if (!f)
                    con++;
            } else if (x >= 48 && x <= 57) {
                n++;
            } else
                return false;
        }
        cout<< ch << " " << v <<" " << con <<endl ; 
        return   v > 0 && ch > 0 && con> 0;
    }
};