bool isSy(struct TreeNode* p, struct TreeNode* q){
    //同时走到空， 结构相同
    if(q == NULL && p == NULL)
        return true;
    //没有同时走到空， 结构不同
    if(q == NULL || p == NULL)
        return false;
    // 对应位置的值以及子结构是否相同
    return p->val == q->val
    && isSy(p->left, q->right)
    && isSy(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL)
        return true;
    return isSy(root->left, root->right);
}