class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st = 0;
        int end = numbers.size() - 1;
        for (int i = 0; i < numbers.size(); i++) {
            int sum = numbers[st] + numbers[end];

            if (sum == target)
                return {st+1, end+1};

            if (sum > target) {
                end--;
            } else {
                st++;
            }
        }

        return {0, 0};
    }
};