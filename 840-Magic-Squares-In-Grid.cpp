class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        vector<pair<int, int>> fives;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 5)
                    fives.push_back({i, j});
            }
        }
        int res = 0;
        for (auto& p : fives) {
            int i = p.first;
            int j = p.second;
            if (i - 1 < 0 || j - 1 < 0 || i + 1 >= n || j + 1 >= m)
                continue;

            bool freq[10] = {0};
            int s = 5;
            freq[grid[i][j]] = true;

            if (grid[i - 1][j] < 10 && !freq[grid[i - 1][j]])
                freq[grid[i - 1][j]] = true;
            else
                continue;

            if (grid[i + 1][j] < 10 && !freq[grid[i + 1][j]]) {
                s += grid[i + 1][j];
                freq[grid[i + 1][j]] = true;
            } else
                continue;

            if (grid[i][j - 1] < 10 && !freq[grid[i][j - 1]])
                freq[grid[i][j - 1]] = true;
            else
                continue;

            if (grid[i][j + 1] < 10 && !freq[grid[i][j + 1]])
                freq[grid[i][j + 1]] = true;
            else
                continue;

            if (grid[i - 1][j - 1] < 10 && !freq[grid[i - 1][j - 1]])
                freq[grid[i - 1][j - 1]] = true;
            else
                continue;

            if (grid[i + 1][j + 1] < 10 && !freq[grid[i + 1][j + 1]])
                freq[grid[i + 1][j + 1]] = true;
            else
                continue;

            if (grid[i - 1][j + 1] < 10 && !freq[grid[i - 1][j + 1]])
                freq[grid[i - 1][j + 1]] = true;
            else
                continue;

            if (grid[i + 1][j - 1] < 10 && !freq[grid[i + 1][j - 1]])
                freq[grid[i + 1][j - 1]] = true;
            else
                continue;

            if (grid[i - 1][j] + grid[i + 1][j] == 10 &&
                grid[i][j - 1] + grid[i][j + 1] == 10 &&
                grid[i - 1][j - 1] + grid[i + 1][j + 1] == 10 &&
                grid[i - 1][j + 1] + grid[i + 1][j - 1] == 10 &&
                grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] ==
                    15 &&
                grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][j - 1] ==
                    15 &&
                grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1] ==
                    15 &&
                grid[i + 1][j + 1] + grid[i][j + 1] + grid[i - 1][j + 1] == 15)
                res++;
        }
        return res;
    }
};