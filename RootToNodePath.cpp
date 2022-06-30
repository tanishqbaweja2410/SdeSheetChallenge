// TC: O(N)
// SC: O(Height of Tree) => O(N) in worst case i.e {Skew Tree}
bool helpFindPath(TreeNode* A, int B, vector<int> &path) {
    if(A == NULL) return false;
    
    path.push_back(A->val);
    if(A->val == B) return true;
    bool leftSubtreeAns = helpFindPath(A->left, B, path);
    if(leftSubtreeAns) return true;
    bool rightSubtreeAns = helpFindPath(A->right, B, path);
    if(!leftSubtreeAns && !rightSubtreeAns) {
        path.pop_back();
        return false;
    }
    return true;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    if(A == NULL) return path;
    bool ans = helpFindPath(A, B, path);
    return path;
}