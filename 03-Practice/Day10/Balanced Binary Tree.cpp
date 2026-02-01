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
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
    int height(TreeNode* root){
        if(root==nullptr)return 0;
        int lh=height(root->left);
        if(lh==-1)return -1;
        int rh=height(root->right);
        if(rh==-1)return -1;
        if(abs(lh-rh)>1)return -1;
        return 1+max(lh,rh); 
    }
};
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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        int lefth=height(root->left);
        int righth=height(root->right);
        return (abs(lefth-righth)<=1)&&isBalanced(root->left)&&isBalanced(root->right);
    }
    int height(TreeNode*root){
        if(root==nullptr)return 0;
        return 1+max(height(root->left),height(root->right));
    }
};