// 29/06/22
class Solution {
public:
    // Recursive Solution
    // TC: O(N)
    // SC: O(Height of Tree) => O(N) in worst case of skew tree
    // int maxDepth(TreeNode* root) {
    //     if(root == NULL) return 0;
    //     return 1 + max(maxDepth(root->left), maxDepth(root->right));
    // }
    
    // Iterative Solution
    // TC: O(N)
    // SC: O(Max Queue Size) => O(N) in worst case of a Complete Binary Tree
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int maximumDepth = 0;
        
        while(!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();
            if(currentNode == NULL) {
                maximumDepth++;
                if(q.empty()) {
                    break;
                }
                else {
                    q.push(NULL);
                }
                continue;
            }
            
            if(currentNode->left) {
                q.push(currentNode->left);
            }
            if(currentNode->right) {
                q.push(currentNode->right);
            }
        }
        return maximumDepth;
    }
};