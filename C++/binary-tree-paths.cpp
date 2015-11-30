// Time:  O(n * h)
// Space: O(h)
// Pre-order DFS
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<string> path;
        if(!root)
            return result;
        path.push_back(to_string(root->val));
        if(!root->left && !root->right)
            result.push_back(to_string(root->val));
        if(root->left)
            dfs(root->left, &result, &path);
        if(root->right)
            dfs(root->right, &result, &path);
        return result;
    }
    
    void dfs(TreeNode* p, vector<string>* result, vector<string>* path){
        path->push_back("->" + to_string(p->val));
        if(!p->left && !p->right)
            result->push_back(join(path));
        if(p->left)
            dfs(p->left, result, path);
        if(p->right)
            dfs(p->right, result, path);
        path->pop_back();
    }
    string join(vector<string>* path){
        string str;
        for(string ele : *path)
            str += ele;
        return str;
    }
};







class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<TreeNode *> path;
        binaryTreePathsRecu(root, &path, &result);
        return result;
    }

    void binaryTreePathsRecu(TreeNode *node, vector<TreeNode *> *path, vector<string> *result) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            string ans = "";
            for (const auto& n : *path) {
                ans.append(to_string(n->val).append("->"));
            }
            result->emplace_back(move(ans.append(to_string(node->val))));
        }
            
        if (node->left != nullptr) {
            path->emplace_back(node);
            binaryTreePathsRecu(node->left, path, result);
            path->pop_back();
        }

        if (node->right != nullptr) {
            path->emplace_back(node);
            binaryTreePathsRecu(node->right, path, result);
            path->pop_back();
        }
    }
};
