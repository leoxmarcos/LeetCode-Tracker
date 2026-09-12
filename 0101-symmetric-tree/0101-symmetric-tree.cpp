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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
    
private:
    bool isMirror(TreeNode* leftNode, TreeNode* rightNode) {
        // If both nodes are null, they are symmetric
        if (!leftNode && !rightNode) return true;
        
        // If only one is null, they are not symmetric
        if (!leftNode || !rightNode) return false;
        
        // Check if values match and respective subtrees are mirrors
        return (leftNode->val == rightNode->val) && 
               isMirror(leftNode->left, rightNode->right) && 
               isMirror(leftNode->right, rightNode->left);
    }
};