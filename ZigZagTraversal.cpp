class Solution {
public:
    // 29/06/22
    // TC: O(N)
    // SC: O(N) + O(N)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if(root == NULL) {
            return result;
        }
        
        vector<int> temp;
        queue<TreeNode*> helpQueue;
        helpQueue.push(root);
        bool leftToRight = true;
        
        while(!helpQueue.empty()) {
            int helpQueueSize = helpQueue.size();
            vector<int> temp(helpQueueSize);  // stores the elements at a particular level
             
            for(int i = 0; i < helpQueueSize; i++) {
                TreeNode* currentNode = helpQueue.front();
                helpQueue.pop();
                
                if(leftToRight) temp[i] = currentNode->val;
                else temp[helpQueueSize - i - 1] = currentNode->val;
                
                if(currentNode->left) {
                    helpQueue.push(currentNode->left);
                }
                if(currentNode->right) {
                     helpQueue.push(currentNode->right);
                }
            }
            
            result.push_back(temp);
            leftToRight = !leftToRight;  // change of order for the next level
        }
        return result;
        
    }
};