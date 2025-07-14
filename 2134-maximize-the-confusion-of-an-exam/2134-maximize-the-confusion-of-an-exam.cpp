class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t = 0;
        int f = 0;
        int j = 0;
        int cur = 0;
        int ans = 0;
        for (int i = 0; i < answerKey.size(); i++) {
            char x = answerKey[i];
            if (x == 'T')
                t++;
            else {
                f++;
            }
            while (i >= j && f > k) {
                char y = answerKey[j++];
                if (y == 'T')
                    t--;
                else
                    f--;
            }
            ans = max(ans , t+f) ; 
        }
        t=0 ; 
        f=0; 
        j=0;
        for (int i = 0; i < answerKey.size(); i++) {
            char x = answerKey[i];
            if (x == 'T')
                t++;
            else {
                f++;
            }
            while (i >= j && t > k) {
                char y = answerKey[j++];
                if (y == 'T')
                    t--;
                else
                    f--;
            }
            ans = max(ans , t+f) ; 
        }


        return ans ; 
    }
};