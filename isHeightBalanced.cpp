class Solution{
    private:
    int height(Node* root) {
        if(root == NULL) return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
    private:
    // TC: O(N*N) 
    bool isBalancedHelp(Node *root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        
        bool isLeftBalanced = isBalanced(root->left);
        bool isRightBalanced = isBalanced(root->right);
        
        if(!isLeftBalanced || !isRightBalanced) return false;
        
        int heightDifference = abs(height(root->left) - height(root->right));
        if(heightDifference <= 1) return true;
        return false;
    }
    // TC: O(N)
    pair<int,bool> isBalancedHelpFast(Node* root) {
        if(root == NULL) return {0, true};
        
        pair<int,bool> leftSubtree = isBalancedHelpFast(root->left);
        pair<int,bool> rightSubtree = isBalancedHelpFast(root->right);
        
        int height = 1 + max(leftSubtree.first, rightSubtree.first);
        int heightDifference = abs(leftSubtree.first - rightSubtree.first);
        bool balanced = leftSubtree.second && rightSubtree.second && (heightDifference <= 1);
        
        return {height, balanced};
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root) 
    {
        return isBalancedHelpFast(root).second;
        
    }
};