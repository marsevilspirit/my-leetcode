#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postorder(struct TreeNode* root, int *res, int *resSize)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left, res, resSize);
    postorder(root->right, res, resSize);
    res[(*resSize)++] = root->val;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int *)malloc(sizeof(int)*2001);
    *returnSize = 0;
    postorder(root, res, returnSize);

    return res;
}
