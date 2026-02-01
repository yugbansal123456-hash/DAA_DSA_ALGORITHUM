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
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return binary(ls,0,ls.size()-1);
    }
    vector<int>ls;
    void inorder(TreeNode*root){
        if(!root)return ;
        inorder(root->left);
        ls.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* binary(vector<int>&list,int l,int h){
        if(l>h)return nullptr;
        int m=l+(h-l)/2;
        TreeNode*root=new TreeNode(list[m]);
        root->left=binary(list,l,m-1);
        root->right=binary(list,m+1,h);
        return root;
    }
};
