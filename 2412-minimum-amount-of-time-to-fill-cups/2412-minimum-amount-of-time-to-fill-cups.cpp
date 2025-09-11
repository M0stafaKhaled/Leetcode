class Solution {
public:
    int fillCups(vector<int>& amount) {

        int steps = 0;

        priority_queue<int> pq;
        for (int i = 0; i < amount.size(); i++) {
            pq.push(amount[i]);
        }

        while (pq.size()) {
            int top = pq.top();
            pq.pop();
            if (top == 0)
                continue;

            steps++;
            top--;
            if (pq.size() && pq.top() > 0) {
                int top2 = pq.top();
                pq.pop();

                top2--;
                if (top2 > 0)
                    pq.push(top2);
            }
            pq.push(top);
        }

        return steps;
    }
};