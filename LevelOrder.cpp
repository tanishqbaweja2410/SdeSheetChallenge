// Codestudio Sol
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
        vector<int> level_order;
        if(root == NULL) return level_order;
        queue<BinaryTreeNode<int>*> help_queue;
        help_queue.push(root);
        help_queue.push(NULL);
        
        while(!help_queue.empty())  {
            BinaryTreeNode<int>* current = help_queue.front();
            help_queue.pop();
            if(current == NULL) {
                if(help_queue.empty()) break;
                help_queue.push(NULL);
            }
            else {
                level_order.push_back(current->val);
                if(current->left) {
                    help_queue.push(current->left);
                }
                if(current->right) {
                    help_queue.push(current->right);
                }
            }
        }
        return level_order;
}

// Leetcode Sol
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level_order;
        if(root == NULL) return level_order;
        queue<TreeNode*> help_queue;
        help_queue.push(root);
        help_queue.push(NULL);
        
        vector<int> temp;
        while(!help_queue.empty())  {
            TreeNode* current = help_queue.front();
            help_queue.pop();
            if(current == NULL) {
                level_order.push_back(temp);
                temp.resize(0);
                if(help_queue.empty()) break;
                help_queue.push(NULL);
            }
            else {
                temp.push_back(current->val);
                if(current->left) {
                    help_queue.push(current->left);
                }
                if(current->right) {
                    help_queue.push(current->right);
                }
            }
        }
        return level_order;
        
    }
};