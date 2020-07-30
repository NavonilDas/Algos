#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // long long DFS(int i, int j, vector<vector<int>> &grid, long long curSum)
    // {
    //     if (i == (grid.size() - 1) && j == (grid[0].size() - 1))
    //     {
    //         return curSum + grid[i][j];
    //     }
    //     if (i >= grid.size() || j >= grid[0].size())
    //         return INT_MAX;

    //     curSum += (long long)grid.at(i).at(j);
    //     return min(
    //         DFS(i + 1, j, grid, curSum),
    //         DFS(i, j + 1, grid, curSum));
    // }
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        int r = grid.size(), c = grid[0].size();

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (i > 0 && j > 0)
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                else if (i == 0 && j > 0)
                    grid[i][j] += grid[i][j - 1];
                else if (i > 0 && j == 0)
                    grid[i][j] += grid[i - 1][j];
            }
        }
        return grid[r - 1][c - 1];
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    Solution s;
    cout << s.minPathSum(grid);
    return 0;
}