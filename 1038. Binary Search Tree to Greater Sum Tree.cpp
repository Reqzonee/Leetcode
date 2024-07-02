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
    int sum = 0;
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }

        // right call
        int rightcall = helper(root->right);
        sum += root->val;
        root->val = sum;
        int leftcall = helper(root->left);
        
        return sum;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int ans = helper(root);
        return root;
    }
};