// TC: O(N*N)
int diameter(Node* root) {
    if(root == NULL) return 0;

    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1, max(D2, D3));
}

// TC: O(N)
pair<int,int> diameterOptimised(Node* root) {
    if(root == NULL) return {0,0};

    pair<int,int> leftSubTree = diameterOptimised(root->left);
    pair<int,int> rightSubTree = diameterOptimised(root->right);
    
    int leftHeight = leftSubTree.first;
    int rightHeight = rightSubTree.first;
    int D1 = leftHeight + rightHeight;
    int D2 = leftSubTree.second;    
    int D3 = rightSubTree.second;

    return {1 + max(leftHeight, rightHeight), max(D1, max(D2,D3))};
}