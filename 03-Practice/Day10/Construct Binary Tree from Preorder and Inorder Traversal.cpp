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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inm;
        for(int i=0;i<inorder.size();i++){
            inm[inorder[i]]=i;
        }
        int pre=0;
        return order(preorder,inorder,pre,0,inorder.size()-1,inm);
    }
    TreeNode* order(vector<int>& preorder, vector<int>& inorder,int &pre,int s,int e,     
    unordered_map<int,int>&inm){
        if(e<s)return nullptr;
        int rootv=preorder[pre++];
        TreeNode*root=new TreeNode(rootv);
        int f=inm[rootv];
        root->left=order(preorder,inorder,pre,s,f-1,inm);
        root->right=order(preorder,inorder,pre,f+1,e,inm);

        return root;
    }
};