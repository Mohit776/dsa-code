/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,
                              int& preIdx, int left, int right) {
        if (left > right) {
            return NULL;
        }

        int rootVal = preorder[preIdx];  // save current root
        TreeNode* root = new TreeNode(rootVal);
        preIdx++; // move preorder index forward

        int inIdx = search(inorder, left, right, rootVal);

        root->left = buildTreeHelper(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = buildTreeHelper(preorder, inorder, preIdx, inIdx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return buildTreeHelper(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};
