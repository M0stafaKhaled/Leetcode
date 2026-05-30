class Solution {
public:
    struct BIT {
        vector<int> tree;
        int n;

        BIT(int size) {
            n = size;
            tree.assign(n + 1, 0);
        }

        void update(int idx, int value) {
            while (idx <= n) {
                tree[idx] = max(tree[idx], value);
                idx += idx & -idx;
            }
        }

        int getMax(int idx) {
            int ans = 0;

            while (idx > 0) {
                ans = max(ans, tree[idx]);
                idx -= idx & -idx;
            }

            return ans;
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries) {
        int maxX = 0;

        for (const auto& query : queries) {
            maxX = max(maxX, query[1]);
        }

        int sentinel = maxX + 1;

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(sentinel);

       
        for (const auto& query : queries) {
            if (query[0] == 1) {
                obstacles.insert(query[1]);
            }
        }

        BIT bit(sentinel + 2);

       
        int previous = 0;

        for (int current : obstacles) {
            if (current == 0) {
                continue;
            }

            bit.update(current, current - previous);
            previous = current;
        }

        vector<bool> reversedAnswers;

 
        for (int i = queries.size() - 1; i >= 0; i--) {
            int type = queries[i][0];
            int x = queries[i][1];

            if (type == 2) {
                int size = queries[i][2];

                auto it = obstacles.upper_bound(x);
                int lastObstacle = *prev(it);

                int bestGap = max(
                    bit.getMax(lastObstacle),
                    x - lastObstacle
                );

                reversedAnswers.push_back(bestGap >= size);
            } else {
               
                auto it = obstacles.find(x);

                int left = *prev(it);
                int right = *next(it);

                obstacles.erase(it);

               
                bit.update(right, right - left);
            }
        }

        reverse(reversedAnswers.begin(), reversedAnswers.end());

        return reversedAnswers;
    }
};