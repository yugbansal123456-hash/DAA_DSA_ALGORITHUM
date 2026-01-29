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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)return {};
        vector<vector<int>> final;
        queue<TreeNode*>hold;
        TreeNode*curr=root;
        hold.push(curr);
        while(!hold.empty()){
            vector<int> sub;
            TreeNode*till=hold.back();
            do{
                curr=hold.front();
                hold.pop();
                sub.push_back(curr->val);
                if(curr->left) hold.push(curr->left);
                if(curr->right)hold.push(curr->right);
            } while(curr!=till);
            final.push_back(sub);
        }
        return final;
    }
};