class Solution {
public:
    class DSU {
    public:
        vector<vector<pair<int, int>>> pr;
        vector<vector<int>> size;
        vector<vector<bool>> valid;
        DSU(int n, int m) {
            pr = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m));
            size = vector<vector<int>>(n, vector<int>(m, 1));
            valid = vector<vector<bool>>(n, vector<bool>(m, true));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    pr[i][j] = {i, j};
                }
        }

        pair<int, int> find(int x, int y) {
            if (pair<int, int>(x, y) == pr[x][y])
                return pair<int, int>(x, y);
            auto [d1, d2] = pr[x][y];
            return pr[x][y] = find(d1, d2);
        }
        void unvalid(int x, int y) {
            auto [x1, y1] = find(x, y);
            valid[x1][y1] = false;
        }

        bool check(int x, int y) {
            auto [x1, y1] = find(x, y);
            return valid[x1][y1];
        }
        void con(int i, int j, int x, int y) {
            auto px = find(i, j);
            auto py = find(x, y);

            if (px == py)
                return;
            if (size[px.first][px.second] < size[py.first][py.second]) {
                swap(px, py);
            }
            pr[py.first][py.second] = px;
            valid[py.first][py.second] =
                valid[py.first][py.second] && valid[px.first][px.second];
            valid[px.first][px.second] =
                valid[py.first][py.second] && valid[px.first][px.second];
            size[px.first][px.second] += size[py.first][py.second];
        }
    };

    bool check(vector<vector<char>>& board, int x, int y) {
        if (x >= board.size() || x < 0 || y < 0 || y >= board[0].size())
            return false;
        return true;
    }
    void solve(vector<vector<char>>& board) {
        DSU dsu(board.size(), board[0].size());
        int dir[5] = {1, 0, -1, 0, 1};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dir[k];
                        int y = j + dir[k + 1];
                        if (check(board, x, y)) {
                            if (board[x][y] == 'O') {
                                dsu.con(i, j, x, y);
                            }
                        } else {
                            dsu.unvalid(i, j);
                            
                        }
                    }
                }
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {

                if (board[i][j] == 'O') {
                    if (dsu.check(i, j)) {
                        cout<<"test"<<endl ; 
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};