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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val>p->val&&root->val<q->val||root->val>q->val&&root->val<p->val){
            return root;
        }else if(root==p||root==q){
            return root;
        }
        if(root->val>p->val){
            return lowestCommonAncestor(root->left,p,q);
        }else{
            return lowestCommonAncestor(root->right,p,q);
        }
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*p1= root;
        TreeNode*p2= root;
        TreeNode*ans;
        while(p1==p2){
            ans=p1;
            if(p->val<p1->val) p1=p1->left;
            else if (p->val>p1->val) p1=p1->right;
            else p1=p;
            if(q->val<p2->val) p2=p2->left;
            else if(q->val>p2->val) p2=p2->right;
            else p2=q;
        }
        return ans;
    }
};