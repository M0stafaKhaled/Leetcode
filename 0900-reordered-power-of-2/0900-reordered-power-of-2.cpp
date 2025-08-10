class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string cur1 = to_string(n);
        sort(cur1.begin(), cur1.end());
        for (int i = 0; i < 31; i++) {
            int power = 1 << i;
            string cur = to_string(power);
            sort(cur.begin(), cur.end());
            if (cur == cur1)
                return 1;
        }

        return 0;
    }
};