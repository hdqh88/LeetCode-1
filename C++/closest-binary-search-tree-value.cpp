// Time:  O(h)
// Space: O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int val1 = root->val;
        TreeNode* p = target < val1 ? root->left : root->right;
        if(p == NULL)
            return val1;
        int val2 = closestValue(p, target);
        return abs(val1 - target) < abs(val2 - target) ? val1 : val2;
    }
};



 
class Solution2 {
public:
    int closestValue(TreeNode* root, double target) {
        double gap = numeric_limits<double>::max();
        int closest = numeric_limits<int>::max();
        
        while (root) {
            if (abs(static_cast<double>(root->val) - target) < gap) {
                gap = abs(root->val - target);
                closest = root->val;
            }
            if (target == root->val) {
                break;
            } else if (target < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return closest;
    }
};
