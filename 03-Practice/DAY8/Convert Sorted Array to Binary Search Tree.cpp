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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode*root=nullptr;
        int n=nums.size();
        return binary(nums,0,n-1);
        
    }
    TreeNode* binary(vector<int>& nums,int l,int h){
        if(l>h) return NULL;
            int m=l+(h-l)/2;
            TreeNode *root=new TreeNode(nums[m]);
            root->left=binary(nums,l,m-1);
            root->right=binary(nums,m+1,h);
            return root;
        }
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode*root=nullptr;
        int n=nums.size();
        insert(root,nums[n/2]);
        binary(root,nums,0,n/2-1);
        binary(root,nums,n/2+1,n-1);
        return root;
    }
    void binary(TreeNode*&root,vector<int>& nums,int l,int h){
        if(l<=h){
            int m=l+(h-l)/2;
            insert(root,nums[m]);
            binary(root,nums,l,m-1);
            binary(root,nums,m+1,h);
        }
    }
    void insert(TreeNode*&root,int val){
        TreeNode* temp=new TreeNode({val});
        if(root==nullptr){
            root=temp;
            return;
        }
        TreeNode*curr=root;
        TreeNode*pre;
        while(curr){
            pre=curr;
            if(val>curr->val) curr=curr->right;
            else curr=curr->left;
        }
        if(val>pre->val) pre->right=temp;
        else  pre->left=temp;
    }
};