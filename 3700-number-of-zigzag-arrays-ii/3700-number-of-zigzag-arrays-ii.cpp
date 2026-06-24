class Solution {
public:
    static const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix& A, Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix A, long long exp) {
        int n = A.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp > 0) {
            if (exp & 1) {
                res = multiply(A, res);
            }

            A = multiply(A, A);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        auto down = [&](int v) {
            return v;
        };

        auto up = [&](int v) {
            return m + v;
        };

        Matrix T(S, vector<long long>(S, 0));

        for (int v = 0; v < m; v++) {
           
            for (int y = 0; y < v; y++) {
                T[up(y)][down(v)] = 1;
            }

            
            for (int y = v + 1; y < m; y++) {
                T[down(y)][up(v)] = 1;
            }
        }

        vector<long long> base(S, 1);

        Matrix P = power(T, n - 1);

        vector<long long> finalState(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                finalState[i] = (finalState[i] + P[i][j] * base[j]) % MOD;
            }
        }

        long long ans = 0;
        for (long long x : finalState) {
            ans = (ans + x) % MOD;
        }

        return ans;
    }
};