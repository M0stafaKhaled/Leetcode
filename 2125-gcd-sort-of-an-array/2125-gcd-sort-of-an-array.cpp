class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n);
            size.assign(n, 1);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }
        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                if (size[a] < size[b])
                    swap(a, b);
                parent[b] = a;
                size[a] += size[b];
            }
        }
    };

    vector<int> spf;

    void sieve(int n) {
        spf.resize(n + 1);
        iota(spf.begin(), spf.end(), 0);
        for (int i = 2; i * i <= n; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    vector<int> getFactors(int x) {
        vector<int> f;
        while (x > 1) {
            int p = spf[x];
            f.push_back(p);
            while (x % p == 0)
                x /= p;
        }
        return f;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    bool gcdSort(vector<int>& nums) {

        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        DSU dsu(arr.back() + 1);
        sieve(arr.back() + 1);
        for (int x : nums) {
            for (int f : getFactors(x)) {
                dsu.unite(x, f);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (dsu.find(nums[i]) != dsu.find(arr[i]))
                return 0;
        }

        return 1;
    }
};