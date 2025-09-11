class Solution {
public:
    bool isPossible(vector<int>& target) {

        long long sum = 0;
        priority_queue<int> pq;
        for (int i = 0; i < target.size(); i++) {
            pq.push(target[i]);
            sum += target[i];
        }

        while (pq.size()) {
            int top = pq.top();
            pq.pop();
            long long  re = sum - top;
            if (top == 1 || re == 1)
                return 1;

            if (re == 0 || re > top)
                return 0;
            int pre = top % re;
            if (pre == 0)
                return 0;

            sum = pre + re;
            pq.push(pre);
        }

        return 1;
    }
};