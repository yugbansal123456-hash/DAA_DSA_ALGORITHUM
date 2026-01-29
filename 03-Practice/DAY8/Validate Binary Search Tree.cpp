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
    bool isValidBST(TreeNode* root) {
        return validate(root,LONG_MIN,LONG_MAX);
    }
    bool validate(TreeNode* root,long minc,long maxc){
        if(root==nullptr) return true;
        if(root->val<=minc||root->val>=maxc)return false;
        return validate(root->right,root->val,maxc)&&validate(root->left,minc,root->val);
    }
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i=1;i<cl.size();i++){
            if(cl[i]<=cl[i-1]) return false;
        }
        return true;
    }
    vector<int>cl;
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        cl.push_back(root->val);
        inorder(root->right);
    }
};