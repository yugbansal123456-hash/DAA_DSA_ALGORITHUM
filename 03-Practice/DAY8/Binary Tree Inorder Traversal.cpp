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
vector<int>r;
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return r;
    }
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        r.push_back(root->val);
        inorder(root->right);
    }
};
class Solution {
public:
vector<int>r;
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return r;
    }
    void inorder(TreeNode* root){
        stack<TreeNode*>st;
        TreeNode*curr= root;
        while(curr!=nullptr||!st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            r.push_back(curr->val);
            curr=curr->right;
        }
    }
};