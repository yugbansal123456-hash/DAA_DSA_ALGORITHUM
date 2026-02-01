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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path;
        find(root, target, path);
        reverse(path.begin(), path.end());
        vector<int> ans;
        for (int i = 0; i < path.size(); i++) {
            TreeNode* curr = path[i];
            TreeNode* blocker = (i == 0 ? nullptr : path[i-1]);
            if (k - i >= 0) {
                dist(curr, k - i, blocker, ans);
            }
        }
        return ans;
    }
    void dist(TreeNode* root, int k, TreeNode* blocker, vector<int>& ans) {
    if (!root || root == blocker) return;   
    if (k == 0) {
        ans.push_back(root->val);
        return;
    }
    dist(root->left, k-1, blocker, ans);
    dist(root->right, k-1, blocker, ans);
}
    bool find(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) return false;
        if (root == target) {
            path.push_back(root);
            return true;
        }
        path.push_back(root);
        if (find(root->left, target, path)) return true;
        if (find(root->right, target, path)) return true;
        path.pop_back();
        return false;
    }
};