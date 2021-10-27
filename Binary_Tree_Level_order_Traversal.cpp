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
        
        vector<vector<int>>v;
        if(root == nullptr) return v;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()) {
            int m=q.size();
            vector<int> temp;
            for(int i=0; i<m; i++) {
                TreeNode * n = q.front();
                q.pop();
                temp.push_back(n->val);
                if(n->left != nullptr) q.push(n->left);
                if(n->right != nullptr) q.push(n->right);
            } v.push_back(temp);     
        } return v;   
    }
};
