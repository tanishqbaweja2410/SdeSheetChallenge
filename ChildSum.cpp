// TC; O(N)
// SC: O(Heigh of Tree) => O(N) in worst case i.e. skew tree
bool isNode(BinaryTreeNode < int > * root) {
    return root != NULL;
}
bool isLeafNode(BinaryTreeNode < int > * root) {
    return root->left == NULL && root->right == NULL;
}
int getChildSum(BinaryTreeNode < int > * root) {
    int sum = 0;
    if(root->left) sum += root->left->data;
    if(root->right) sum += root->right->data;
    return sum;
}
void changeTree(BinaryTreeNode < int > * root) {
    if(!isNode(root) || isLeafNode(root)) return;
    
    // check whether root's data is greater than childSum or not
    int childSum = getChildSum(root);
    if(root->data > childSum) {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    
    // make function calls to left and right subtree
    changeTree(root->left);
    changeTree(root->right);
    
    // update the root's data
    root->data = getChildSum(root);
}  