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
    unordered_map<int, int> mp;
    int maxDepth = 0;

    void depthOfTree(TreeNode* root, int depth) {
        if(!root) return;

        maxDepth = max(maxDepth, depth);
        mp[root->val] = depth;
        depthOfTree(root->left, depth+1);
        depthOfTree(root->right, depth+1);
    }

    TreeNode* LCA(TreeNode* root) {
        if(!root || mp[root->val] == maxDepth) {
            return root;
        }

        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);

        if(l && r) return root;

        return l != NULL ? l : r;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depthOfTree(root, 0);
        return LCA(root);
    }
};