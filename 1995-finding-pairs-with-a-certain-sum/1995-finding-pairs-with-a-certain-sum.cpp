class FindSumPairs {
public:
    unordered_map<int, int> map;
    vector<int> num1, num2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num1 = nums1;
        num2 = nums2;
        for (int i = 0; i < nums2.size(); i++) {
            map[nums2[i]]++;
        }
    }

    void add(int index, int val) {
        int old = num2[index];
        map[old]--;
        if (map[old] == 0)
            map.erase(old);

        num2[index] = val + old;
        map[num2[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (int e : num1) {
            if (map.find(tot - e) != map.end()) {
                ans += map[tot - e];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */