class Solution {
public:
    int arr[14] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int solve(string a, string b) {
        int d1, d2;
        int m1, m2;
        if (b > a)
            return 0;
        if (b == a)
            return 1;
        for (int i = 0; i < 2; i++) {
            d1 *= 10;
            d2 *= 10;
            d1 += (a[i] - '0');
            d2 += (b[i] - '0');
        }
        for (int i = 3; i < 5; i++) {
            m1 *= 10;
            m2 *= 10;
            m1 += (a[i] - '0');
            m2 += (b[i] - '0');
        }

        int ans = ((m1)-m2) + 1;
        cout << d1 << " " << d2 << endl;
        cout << m1 << " " << m2 << endl;
        for (int i = d2; i < d1 && d1 != d2; i++) {

            ans += arr[i];
        }
        return max(ans, 0);
    }
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        pair<string, string> a, b;
        a.first = arriveAlice;
        a.second = leaveAlice;

        b.first = arriveBob;
        b.second = leaveBob;

        pair<string, string> a2, b2;

        a2 = min(a, b);
        b2 = max(a, b);
        cout << a2.second << " " << b2.first << endl;
        int z = solve(min(a2.second, b2.second), b2.first);
        return z;
    }
};