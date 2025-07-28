class NumArray {
public:
    const int N = 3e4;
    int l = 0;
    int r = 0;
    vector<int> seg;
    NumArray(vector<int>& nums) {
        r = nums.size() - 1;
        seg = vector<int>(4 * nums.size());
        build(0, 0, r, nums);
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[node] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid, nums);
        build(2 * node + 2, mid + 1, r, nums);
        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }
    void up(int node, int l, int r, int index, int val) {
        if (l == r && l == index) {
            seg[node] = val;
            return;
        }
        if(l==r) return ; 
        if (l > index)
            return;
        if (index > r)
            return;
        int mid = (l + r) / 2;
        up(2 * node + 1, l, mid, index , val);
        up(2 * node + 2, mid + 1, r, index , val);
        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    void update(int index, int val) {

        up(0 , 0 , r , index ,val) ; 
    }

    int sumRange(int left, int right) { return get(0, 0, r, left, right); }

    int get(int node, int l, int r, int st, int end) {
        if (st > r || end < l)
            return 0;
        if (l >= st && r <= end)
            return seg[node];

        int mid = (l + r) / 2;

        return get(2 * node + 1, l, mid, st, end) +
               get(2 * node + 2, mid + 1, r, st, end);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */