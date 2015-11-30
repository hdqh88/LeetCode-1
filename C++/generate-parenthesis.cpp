// Time Complexity: O(2^n/n)??
// Space Complexity: O(n)
// DFS
class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            dfs(ans, "", 0, 0, n);
            return ans;
        }
        
        void dfs(vector<string> &ans, string s, int l, int r,  int n) {
            if(l==n) {
                ans.push_back(s.append(n-r, ')'));
                return;
            }
            dfs(ans, s+"(", l+1, r, n);
            if(l>r) dfs(ans, s+")", l, r+1, n);
        }
};
