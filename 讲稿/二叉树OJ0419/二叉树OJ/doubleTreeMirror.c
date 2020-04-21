bool isSy(struct TreeNode* p, struct TreeNode* q) {
    //
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL && q == NULL) {
        return false;
    }
    return p->val == q->val
        && isSy(p->left, q->right)
        && isSy(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }
    return isSy(root->left, root->right);
}