/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution
{
public:
#define maxn 5000 + 10
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<string> q;
        map<string, int> d;
        map<string, bool> vis;
        for (int i = 0; i < wordList.size(); ++i)
        {
            vis[wordList[i]] = 1;
        }
        d[beginWord] = 0;
        q.push(beginWord);
        while(!q.empty()){
            string t = q.front();
            q.pop();
            string s = t;
            int n=s.length();
            for(int i = 0; i < n; ++i){
                for (int j = 'a'; j <= 'z';++j){
                    s[i] = j;
                    if(s!=beginWord&&vis.count(s)&&d[s]==0){
                        d[s] = d[t] + 1;
                        q.push(s);
                    }
                }
                s[i] = t[i];
            }
        }
        if(d[endWord]==0)
            return 0;
        return d[endWord]+1;
    }
};
// @lc code=end
