
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> right(m, vector<long long>(n, 0));
        vector<vector<long long>> down(m, vector<long long>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                long long fromLeft = right[i][j];
                long long fromUp = down[i][j];

                // Starting position
                if (i == 0 && j == 0) {
                    fromLeft = 1;
                }

                if (grid[i][j] == 0) {
                    // Empty cell: move right or down
                    long long ways = (fromLeft + fromUp) % MOD;

                    if (j + 1 < n) {
                        right[i][j + 1] =
                            (right[i][j + 1] + ways) % MOD;
                    }

                    if (i + 1 < m) {
                        down[i + 1][j] =
                            (down[i + 1][j] + ways) % MOD;
                    }
                }
                else {
                    // Mirror: left arrival turns down
                    // Up arrival turns right

                    if (i + 1 < m) {
                        down[i + 1][j] =
                            (down[i + 1][j] + fromLeft) % MOD;
                    }

                    if (j + 1 < n) {
                        right[i][j + 1] =
                            (right[i][j + 1] + fromUp) % MOD;
                    }
                }
            }
        }

        return (right[m - 1][n - 1] +
                down[m - 1][n - 1]) % MOD;
    }
};
