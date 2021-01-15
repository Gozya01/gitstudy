/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
#define  maxn  100 + 10
    bool f[maxn][maxn][2];
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(),m=s2.length(),l=s3.length();
        if(l!=n+m)
            return 0;
        f[0][0][0] = 1;
        f[0][0][1] = 1;
        for(int i=0;i<=n;i++){
            for (int j = 0; j <=m;++j){
                if(f[i][j][0]||f[i][j][1]){
                    for (int k = i+1;k<=n;k++){
                        for (int q = j + 1; q <= m;q++){
                            if(f[i][j][0]&&s1.substr(i,k-i)+s2.substr(j,q-j)==s3.substr(i+j,k+q-i-j)){
                                f[k][q][0] = 1;
                            }
                            if(f[i][j][1]&&s2.substr(j,q-j)+s1.substr(i,k-i)==s3.substr(i+j,k+q-i-j)){
                                f[k][q][1] = 1;
                            }

                        }
                    }
                }
            }
        }
        if(f[n][m][0]||f[n][m][1])return 1;
        for (int i = 0; i <= n;++i){
            if(f[i][m][0]&&s1.substr(i,n-i)==s3.substr(i+m,n-i))
                return 1;
        }
        for (int j = 0; j <= m;++j){
            if(f[n][j][1]&&s2.substr(j,m-j)==s3.substr(j+n,m-j))
                return 1;
        }
        return 0;
    }
};
// @lc code=end

