/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // TC: O(N)
    // SC: O(N){skew tree worst case}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;
        
        bool isLeftSubtreeSame = isSameTree(p->left, q->left);
        bool isRightSubtreeSame = isSameTree(p->right, q->right);
        
        if(!isLeftSubtreeSame || !isRightSubtreeSame) return false;
        return p->val == q->val;
    }
};