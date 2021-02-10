/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution
{
public:
    bool flag1[100][100], flag2[100][100], flag3[100][100];
    bool flag = 0;
    void Dfs(vector<vector<char>> &s, int n, int m)
    {
        if (n == 9)
        {
            flag = 1;
            return;
        }
        if (flag)
            return;
        if (s[n][m]!='.')
        {
            if (m == 8)
                Dfs(s, n + 1, 0);
            else
                Dfs(s, n, m + 1);
            return;
        }
        int k = n / 3 * 3 + m / 3 + 1;
        for (int i = 1; i <= 9; ++i)
            {if (flag)
                    return;
            if (s[n][m]!='.')
                continue;
            if (flag1[n][i] == 0 && flag2[m][i] == 0 && flag3[k][i] == 0)
            {
                flag1[n][i] = flag2[m][i] = flag3[k][i] = 1;
                s[n][m] =48+i;
                if (m == 8)
                    Dfs(s, n + 1, 0);
                else
                    Dfs(s, n, m + 1);
                if (flag)
                    return;
                flag1[n][i] = flag2[m][i] = flag3[k][i] = 0;
                s[n][m] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                int k = i / 3 * 3 + j / 3 + 1;
                int z = board[i][j] - 48;
                flag1[i][z] = flag2[j][z] = flag3[k][z] = 1;
            }
        }
        Dfs(board, 0, 0);
    }
};

// @lc code=end

