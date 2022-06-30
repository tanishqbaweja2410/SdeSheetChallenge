class Solution {
public:
    // 30/06/22
    // TC: O(N)
    // SC: O(N){queue}
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) return 0;
        queue<pair<TreeNode*, long long>> helpQueue;  // {root, index}
        helpQueue.push({root, 0});
        int maxWidth = 0;

        while(!helpQueue.empty()) {

            int queueSize = helpQueue.size();
            long long currentLevelWidth = helpQueue.back().second - helpQueue.front().second + 1;
            if(currentLevelWidth > maxWidth) maxWidth = currentLevelWidth;

            // traversing the nodes, popping them & inserting their children
            // with modification of their index => to avoid overflow
            long long minIndex = helpQueue.front().second;
            for(int i = 0; i < queueSize; i++) {
                auto currentPair = helpQueue.front();
                TreeNode* currentNode = currentPair.first;
                long long currentIndex = currentPair.second;
                helpQueue.pop();

                if(currentNode->left) {
                    helpQueue.push({currentNode->left, 2 * (currentIndex - minIndex) + 1});
                }
                if(currentNode->right) {
                    helpQueue.push({currentNode->right, 2 * (currentIndex - minIndex) + 2});
                }
            }
        }
        return maxWidth;

    }
        
    
};