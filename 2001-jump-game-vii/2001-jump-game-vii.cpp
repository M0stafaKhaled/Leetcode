class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        vector<int> db(s.size() + 11);

        cout << s.size() << endl;
        int n = s.size() - 1;
        if (s[n] == '1')
            return 0;

       
        db[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0')
                continue;
            int st = i + minJump;
            int end = min(n, i + maxJump);
            if (st > n)
                continue;
            db[st]++;
            db[end + 1]--;
        }
        for (int i = 1; i <= n; i++) {
            db[i] += db[i - 1];
        }
        for (int i = 0; i <= n; i++) {
            cout << db[i] << " ";
        }
     int max_f = maxJump;
        int min_f = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != '0' || db[i] == 0)
                continue;
            if (i > max_f)
             {  cout<<"test"<<endl;
                   return 0;
             }

            int st = i + minJump;
            int end = min(n, i + maxJump);
            if (st > n)
                continue;
            if (end >= n)
                return 1;

            max_f = end;
        }

        return db[n] >= 1;
    }
};