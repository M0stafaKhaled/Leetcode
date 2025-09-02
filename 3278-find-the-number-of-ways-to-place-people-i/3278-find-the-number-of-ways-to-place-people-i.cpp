class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                int ax = points[i][0], ay = points[i][1];
                int bx = points[j][0], by = points[j][1];

                if (ax <= bx && ay >= by && (ax < bx || ay > by)) {
                    bool valid = true;

                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j)
                            continue;
                        int px = points[k][0], py = points[k][1];

                        if (ax <= px && px <= bx && by <= py && py <= ay) {
                            if (ax == bx) {
                                if (px == ax && by < py && py < ay) {
                                    valid = false;
                                    break;
                                }
                            } else if (ay == by) {
                                if (py == ay && ax < px && px < bx) {
                                    valid = false;
                                    break;
                                }
                            } else {
                                valid = false;
                                break;
                            }
                        }
                    }

                    if (valid)
                        ans++;
                }
            }
        }

        return ans;
    }
};
