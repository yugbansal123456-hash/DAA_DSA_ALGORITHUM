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
    int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        int left=1+maxDepth(root->left);
        int right=1+maxDepth(root->right);
        return max(left,right);
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)return {};
        queue<TreeNode*>hold;
        TreeNode*curr=root;
        hold.push(curr);
        int lv=0;
        while(!hold.empty()){
            TreeNode*till=hold.back();
            int n=hold.size();
            lv++;
            for(int i=0;i<n;i++){
                curr=hold.front();hold.pop();
                if(curr->left) hold.push(curr->left);
                if(curr->right)hold.push(curr->right);
            }        
            }
        return lv;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return dep(root,0);
    }
    int dep(TreeNode* root,int d){
        if(root==nullptr)return d;
        int l=dep(root->left,d+1);
        int r=dep(root->right,d+1);
        return max(l,r);
    }
};