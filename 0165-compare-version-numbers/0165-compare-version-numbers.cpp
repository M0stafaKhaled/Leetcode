class Solution {
public:
    int compareVersion(string v1, string v2) {

        int i = 0;
        int j = 0;

        while (i < v1.size() && j < v2.size()) {
            int t1 = 0;
            int t2 = 0;
            while (i < v1.size() && v1[i] != '.') {
                t1 = t1 * 10;
                t1 += v1[i++] - '0';
            }
            while (j < v2.size() && v2[j] != '.') {
                t2 = t2 * 10;
                t2 += v2[j++] - '0';
            }
            //  cout << t1 << " " << t2 << endl;
            if (t1 == t2) {
                i++;
                j++;
                continue;
            }
            if (t1 > t2)
                return 1;
            return -1;
        }

        while (i < v1.size()) {
            if (v1[i] == '0' || v1[i] == '.') {
                i++;
                continue;
            }

            return 1;
        }

        while (j < v2.size()) {
            if (v2[j] == '0' || v2[j] == '.') {
                j++;
                continue;
            }

            return -1;
        }
        return 0;
    }
};