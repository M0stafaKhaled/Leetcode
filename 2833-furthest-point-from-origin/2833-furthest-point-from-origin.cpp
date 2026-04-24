class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int a, b, c;
        a= b =c = 0 ; 

        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'R')
                a++;
            else if (moves[i] == 'L')
                b++;
            else
                c++;
        }

        if (a >= b)
            return (a - b) + c;
        return (b - a) + c;
    }
};