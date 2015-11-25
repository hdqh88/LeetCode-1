// Time:  O(max(h, k))
// Space: O(min(h, k))

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// DFS
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
    int dfs(TreeNode* p, int& k){
        if(!p->left && !p->right){
            --k;
            return p->val;
        }
        int x = p->left ? dfs(p->left, k) : p->val;
        if(k == 0)
            return x;
        if(--k == 0)
            return p->val;
        return p->right ? dfs(p->right, k) : p->val;
    }
};



class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        deque<TreeNode *> s;
        TreeNode *cur = root;
        int rank = 0;
        while (!s.empty() || cur) {
            if (cur) {
                s.emplace_back(cur);
                if (s.size() > k) {
                    s.pop_front();
                }
                cur = cur->left;
            } else {
                cur = s.back();
                s.pop_back();
                if (++rank == k) {
                    return cur->val;
                }
                cur = cur->right;
            }
        }

        return INT_MIN;
    }
};
 
// Time:  O(max(h, k))
// Space: O(h)
class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> s;
        TreeNode *cur = root;
        int rank = 0;
        while (!s.empty() || cur) {
            if (cur) {
                s.emplace(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                if (++rank == k) {
                    return cur->val;
                }
                cur = cur->right;
            }
        }

        return INT_MIN;
    }
};
