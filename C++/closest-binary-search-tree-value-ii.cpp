// Time:  O(h + k)
// Space: O(h)

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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> result;
        stack<int> s1, s2;
        inorder(root, target, false, &s1);
        inorder(root, target, true, &s2);
        
        while(k-- > 0){
            if(s1.empty()){
                result.push_back(s2.top());
                s2.pop();
            }else if(s2.empty()){
                result.push_back(s1.top());
                s1.pop();
            }else if(abs(s1.top() - target) < abs(s2.top() - target)){
                result.push_back(s1.top());
                s1.pop();
            }else{
                result.push_back(s2.top());
                s2.pop();
            }
        }
        return result;
    }
    
    void inorder(TreeNode* p, int target, bool reverse, stack<int>* s){
        if(!p) return;
        inorder(reverse ? p->right : p->left, target, reverse, s);
        if((!reverse && p->val <= target) || (reverse && p->val > target))
            s->push(p->val);
        inorder(reverse ? p->left : p->right, target, reverse, s);
    }
};



class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // The forward or backward iterator.
        const auto backward = [](const vector<TreeNode*>& s) { return s.back()->left; };
        const auto forward = [](const vector<TreeNode*>& s) { return s.back()->right; };
        const auto closest = [&target](const TreeNode* a, const TreeNode* b) { 
                                return abs(a->val - target) < abs(b->val - target); 
                            };

        // Build the stack to the closest node.
        vector<TreeNode*> s;
        while (root) {
            s.emplace_back(root);
            root = target < root->val ? root->left : root->right;
        }

        // Get the stack to the next smaller node.
        vector<TreeNode*> forward_stack(s.cbegin(), next(min_element(s.cbegin(), s.cend(), closest)));
        vector<TreeNode*> backward_stack(forward_stack);
        nextNode(backward_stack, backward, forward);
    
        // Get the closest k values by advancing the iterators of the stacks.
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (!forward_stack.empty() && 
                (backward_stack.empty() || closest(forward_stack.back(), backward_stack.back()))) {
                result.emplace_back(forward_stack.back()->val);
                nextNode(forward_stack, forward, backward);
            } else if (!backward_stack.empty() &&
                       (forward_stack.empty() || !closest(forward_stack.back(), backward_stack.back()))) {
                result.emplace_back(backward_stack.back()->val);
                nextNode(backward_stack, backward, forward);
            }
        }
        return result;
    }
    
    // Helper to make a stack to the next node.
    template<typename T, typename U>
    void nextNode(vector<TreeNode*>& s, const T& child1, const U& child2) {
        if (!s.empty()) {
            if (child2(s)) {
                s.emplace_back(child2(s));
                while (child1(s)) {
                    s.emplace_back(child1(s));
                }
            } else {
                auto child = s.back();
                s.pop_back();
                while (!s.empty() && child == child2(s)) {
                    child = s.back();
                    s.pop_back();
                }
            }
        }
    }
};
