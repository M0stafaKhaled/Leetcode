class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums, vector<int>& arr) {

        if (idx == nums.size()) {
            ans.push_back(arr);
            return;
        }
        if (arr.size() == nums.size()) {
            ans.push_back(arr);
            return;
        }
        if (arr.size() > nums.size())
            return;

        solve(idx + 1, nums, arr);
        arr.push_back(nums[idx]);
        solve(idx + 1, nums, arr);
        arr.pop_back() ; 
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        solve(0, nums, arr);
        return ans;
    }
};