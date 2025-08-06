class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, data);
    }

    void build(int node, int l, int r, const vector<int>& data) {
        if (l == r) {
            tree[node] = data[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, data);
        build(2 * node + 1, mid + 1, r, data);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int l, int r, int val) {
        if (tree[node] < val) return -1;
        if (l == r) return l;
        int mid = (l + r) / 2;
        int left = query(2 * node, l, mid, val);
        if (left != -1) return left;
        return query(2 * node + 1, mid + 1, r, val);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2 * node, l, mid, idx, val);
        else update(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int findLeftmost(int val) {
        return query(1, 0, n - 1, val);
    }

    void markUsed(int idx) {
        update(1, 0, n - 1, idx, -1); 
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree seg(baskets);
        int unplaced = 0;

        for (int fruit : fruits) {
            int idx = seg.findLeftmost(fruit);
            if (idx == -1) {
                unplaced++;
            } else {
                seg.markUsed(idx);
            }
        }

        return unplaced;
    }
};
