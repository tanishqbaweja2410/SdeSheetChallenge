/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

class Solution{
private:
    // Using 2 explicit stacks 
    // TC: O(N)
    // SC: O(N + N)
    void getPostOrderTwoStacks(TreeNode *root, vector<int> &postorder) {
    stack<TreeNode*> helpSet1, helpSet2;
    helpSet1.push(root);

    while(!helpSet1.empty()) {
        TreeNode* atTop = helpSet1.top();
        helpSet1.pop();
        helpSet2.push(atTop);
        if(atTop->left != NULL) {
            helpSet1.push(atTop->left);
        }
        if(atTop->right != NULL) {
            helpSet1.push(atTop->right);
        }
    }

    while(!helpSet2.empty()) {
        postorder.push_back(helpSet2.top()->val);
        helpSet2.pop();
    }
}
private:
// Using a Single Stack
// TC: O(2 * N)
// SC: O(N)
void getPostOrderOneStack(TreeNode *root, vector<int> &postorder) {

    stack<TreeNode*> helpSet;
    TreeNode* currentNode = root;

    while(currentNode != NULL || !helpSet.empty()) {
        if(currentNode != NULL) {
            helpSet.push(currentNode);
            currentNode = currentNode->left;
        }
        else {
            TreeNode* temp = helpSet.top()->right;
            if(temp == NULL) {
                temp = helpSet.top();
                helpSet.pop();
                postorder.push_back(temp->val);
                while(!helpSet.empty() && temp == helpSet.top()->right) {
                    temp = helpSet.top();
                    helpSet.pop();
                    postorder.push_back(temp->val);
                }
            }
            else {
                currentNode = temp;
            }
        }
    }
}
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        if(root == NULL) return postorder;

        // using two stacks
        // getPostOrderTwoStacks(root, postorder);

        // using single stack
        getPostOrderOneStack(root, postorder);
        return postorder;
    }
};