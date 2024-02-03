bool judge(struct TreeNode *p ,struct TreeNode *q){
    if(p == NULL && q == NULL){
        return true;
    }
    else if(p == NULL || q == NULL){
        return false;
    }
    else if(p -> val != q -> val){
        return false;
    }
    return judge(p -> left,q -> right) && judge(p -> right,q -> left);
}
bool isSymmetric(struct TreeNode* root){
    return judge(root -> left,root -> right);
}

