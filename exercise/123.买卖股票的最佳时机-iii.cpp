/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
/*
f[i][2][2]
f[i][0][0] 第一次交易买股票的最小花费
f[i][0][1] 第一次交易卖股票的最大利润
f[i][1][0] 第二次买股票的最小花费+这之前的最大利润
f[i][1][1] 第二次卖股票的最大利润
f[i][0][0]=max(f[i-1][0][0],-a[i])
f[i][0][1]=max(f[i-1][0][1],a[i]+f[i][0][0]);
f[i][1][0]=max(f[i-1][1][0],f[i-1][0][1]-a[i]);
f[i][]
*/
class Solution {
public:
#define maxn 100000+10
    int f[maxn][2][2];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        f[0][0][0] = -prices[0];
        f[0][0][1] = 0;
        f[0][1][0] = -prices[0];
        f[0][1][1] = 0;
        for (int i = 1; i < n;++i){
            f[i][0][0] = max(f[i - 1][0][0], -prices[i]);
            f[i][0][1] = max(f[i - 1][0][1], prices[i] + f[i][0][0]);
            f[i][1][0] = max(f[i - 1][1][0], f[i - 1][0][1] - prices[i]);
            f[i][1][1] = max(f[i - 1][1][1], prices[i] + f[i][1][0]);
            // printf("%d %d %d %d %d\n", i, f[i][0][0], f[i][0][1], f[i][1][0], f[i][1][1]);
        }
        int ans;
        ans = max(f[n - 1][0][1], f[n - 1][1][1]);
        return ans;
    }
};
// @lc code=end

