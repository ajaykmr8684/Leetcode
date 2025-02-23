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
    TreeNode* solve(int prestart, int poststart, int preend, vector<int> &preorder, vector<int> &postorder, unordered_map<int, int> umap) {
        if(prestart > preend) return NULL;

        TreeNode* root = new TreeNode(preorder[prestart]);
        if(prestart == preend) return root;

        int nextNode = preorder[prestart + 1];

        int j = umap[nextNode];

        int numOfNodes = j - poststart + 1;

        root->left = solve(prestart+1, poststart, prestart + numOfNodes, preorder, postorder, umap);
        root->right = solve(prestart + numOfNodes + 1, j + 1, preend, preorder, postorder, umap);
        return root;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        unordered_map<int, int> umap;
        for(int i = 0; i < n; ++i) umap[postorder[i]] = i;
        return solve(0, 0, n-1, preorder, postorder, umap);

    }
};