/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = ances(root, startValue, destValue);
        string pathToStart, pathToDest;
        find(lca, startValue, pathToStart);  
        find(lca, destValue, pathToDest);
        string up(pathToStart.size(), 'U');
        return up + pathToDest;
    }
private:
    TreeNode* ances(TreeNode* root, int s, int d) {
        if (!root) return nullptr;
        if (root->val == s || root->val == d) return root;
        TreeNode* left = ances(root->left, s, d);
        TreeNode* right = ances(root->right, s, d);
        if (left && right) return root;
        return left ? left : right;
    }
    bool find(TreeNode* root, int target, string& path) {
        if (!root) return false;
        if (root->val == target) return true;
        path.push_back('L');
        if (find(root->left, target, path)) return true;
        path.pop_back();
        path.push_back('R');
        if (find(root->right, target, path)) return true;
        path.pop_back();
        return false;
    }
};