class Solution {
public:
   map<pair<double , double> , double> db ; 
    double solve(int a, int b) {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1;
        if (b <= 0)
            return 0;
        if(db.find({a, b}) != db.end()) return db[{a,b}] ; 

        return db[{a, b}] =  0.25 * (solve(a - 100, b) + solve(a - 75, b - 25) +
                      solve(a - 50, b - 50) + solve(a - 25, b - 75));
    }
    double soupServings(int n) {
        if (n >= 5000)
            return 1;
        //memset(db , -1 , sizeof db) ; 
        return solve(n, n);
    }
};