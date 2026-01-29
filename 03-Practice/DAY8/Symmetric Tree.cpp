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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        return check(root->left,root->right);
    }
    bool check(TreeNode* s1,TreeNode* s2){
        if(!s1&&!s2)return true;
        if(!s1||!s2||s1->val!=s2->val)return false;
        return check(s1->left,s2->right)&&check(s2->left,s1->right);
    }
};