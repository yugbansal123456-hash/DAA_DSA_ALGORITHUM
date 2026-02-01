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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        TreeNode*curr=root;
        queue<TreeNode*>list;
        list.push(root);
        int level=0;
        vector<vector<int>>ans;
        while(list.size()!=0){
            int n=list.size();
            vector<int>sub;
            for(int i=1;i<=n;i++){
                curr=list.front();
                list.pop();
                sub.push_back(curr->val);
                if(curr->left)list.push(curr->left);
                if(curr->right)list.push(curr->right);
            }
            if(level%2==1){
                reverse(sub.begin(),sub.end());
            }
            level++;
            ans.push_back(sub);
        }
        return ans;
    }
};