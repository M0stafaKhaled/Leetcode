class Solution {
public:
    string convert(int n) {

        string ans = "";
        while (n) {
            int d = n % 2;
            ans += (d + '0');
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool queryString(string s, int n) {
        int sz = s.size() ; 
        if (n >= (1 << 20)) return false;
        for (int i = 1; i <= n; i++) {
            string d = convert(i);
      //      cout << i << " " << d << endl;
            if (s.find(d) == std::string::npos) {

                return 0;
            }
        }

        return 1;
    }
};