class Solution {
public:
    int bestClosingTime(string customers) {

        int n = customers.size();
        int s = 0;
        for (int i = 0; i < customers.size(); i++) {
            int cur = customers[i] == 'Y';
            s += cur;
            //  cout << s << endl;
        }
        int pre = 0;
        int ans = n;
        int index = 0;
        int i = 0;
        for (; i < customers.size(); i++) {

            if (s + pre < ans) {
                ans = s + pre;
                index = i;
            }

            pre += customers[i] == 'N';
            s -= (customers[i] == 'Y');
        }
        if (s + pre < ans) {
            ans = s + pre;
            index = i;
        }
        return index;
    }
};