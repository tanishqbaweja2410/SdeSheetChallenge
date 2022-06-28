void inorderTraversal(BinaryTreeNode<int>* root,  vector<int> &inorder) {
    if(root == NULL) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

// TC: O(N + N/2) SC: O(N)
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.   
    vector<int> inorder;
    inorderTraversal(root, inorder);
    
    int n = inorder.size();
    for(int i = 0; i < n/2; i++) {
        if(inorder[i] != inorder[n - i - 1]) return false;
    }
    return true;
    
}