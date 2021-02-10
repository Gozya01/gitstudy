/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
private:
    const int add = 1e9;
    unordered_map<int, int> q;
    vector<int> s;
    vector<int> fa;

public:
    int Find(int x){
        if(fa[x]==x)return x;
        return fa[x] = Find(fa[x]);
    }
    void Insert(int x,int y){
        int fx=Find(x),fy=Find(y);
        if(fx==fy)
            return;
        fa[fx] = fy;
        s[fy] += s[fx];
    }
    int longestConsecutive(vector<int>& nums) {
        for (int i = 0; i < nums.size();++i)
        {
            nums[i] += add;
            q[nums[i]] = i;
            s.push_back(1);
            fa.push_back(i);
        }
        for(int i:nums){
            if(q.count(i-1)){
                Insert(q[i - 1], q[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < nums.size();++i){
            ans = max(ans, s[i]);
        }
        return ans;
    }
};
// @lc code=end

