class Solution {
public:
    int bitwiseComplement(int n) {

        int end = 0;
        for (int i = 0; i < 31; i++) {
            int cur = (n >> i) & 1;
            if (cur)
                end = i;
        }
        
        int d = 1<<(end+1) ; 
        d-- ; 


        return d^n;
    }
};