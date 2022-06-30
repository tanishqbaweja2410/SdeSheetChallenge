// 30/06/22
// Approach1 : find root to node paths for both the nodes, and the latermost matching node is the Lowest Common Ancestor of the two nodes => TC: O(N) & SC: O(N) for storing the path for each node + auxilliary stack space of recursion 
// Better Approach : -
// TC: O(N)
// SC: O(Height of Tree) => O(N) in worst case of Skew Tree
if(root == NULL) return NULL;

if(root->val == p->val || root->val == q->val) return root;
TreeNode* nodeLeftSubtree = lowestCommonAncestor(root->left, p, q);
TreeNode* nodeRightSubtree = lowestCommonAncestor(root->right, p, q);

if(nodeLeftSubtree && nodeRightSubtree) return root;
if(nodeLeftSubtree && !nodeRightSubtree) return nodeLeftSubtree;
if(!nodeLeftSubtree && nodeRightSubtree) return nodeRightSubtree;
return NULL;