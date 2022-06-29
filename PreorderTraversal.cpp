// Iterative Preorder
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
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> preorder;
    stack<TreeNode *> st;
    TreeNode * temp = root;

    while(true) {
        if(temp != NULL) {
            preorder.push_back(temp->data);
            st.push(temp);
            temp = temp->left;
        }
        else {
            if(st.empty()) break;
            temp = st.top()->right;
            st.pop();
        }
    }
}