/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
#define  maxn 1000 + 10
    int f[maxn][maxn];
    vector<int> list[200];
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        for(int i=0;i<m;i++) {
            list[t[i]].push_back(i);
        }
        for(int i=0;i<n;i++) {
            if(s[i]==t[0])
                f[i][0] = 1;
        }
        for (int i = 0; i < n;++i){
            for(int k=0;k<list[s[i]].size();++k){
                for (int j = 0; j < i;++j){
                    if(!list[s[i]][k])
                        break;
                    f[i][list[s[i]][k]]+=f[j][list[s[i]][k]-1];
                    if(f[i][list[s[i]][k]]>=1e9)f[i][list[s[i]][k]]-=1e9;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n;++i){
            ans += f[i][m - 1];
        }
        return ans;
    }
};
// @lc code=end

