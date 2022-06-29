// Iterative Inorder
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
// TC: O(N)
// SC: O(N) in worst case i.e. in case of a skew tree => O(height of tree)
vector<int> getInOrderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *temp = root;
    vector<int> inorder;
    while(true) {
    	if(temp != NULL) {
    		st.push(temp);
    		temp = temp->left;
    	}
    	else {
    		if(st.empty()) break;
    		temp = st.top();
    		st.pop();
    		inorder.push_back(temp->data);
    		temp = temp->right;
    	}
    }
    return inorder;
}