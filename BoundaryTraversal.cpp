// TC: O(N)
// SC: O(Height of Tree) i.e. in worst case O(N)
class Solution {
private:
    void traverseLeft(Node* root, vector<int> &result) {
        if((root == NULL) || (root->left == NULL && root->right == NULL)) return;
        
        result.push_back(root->data);
        if(root->left) {
            traverseLeft(root->left, result);
        }
        else {
            traverseLeft(root->right, result);
        }
    }
private:
    void traverseLeaf(Node* root, vector<int> &result) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            result.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, result);
        traverseLeaf(root->right, result);
    }
private:
    void traverseRight(Node* root, vector<int> &result) {
        if((root == NULL) || (root->left == NULL && root->right == NULL)) return;
        
        if(root->right) {
            traverseRight(root->right, result);
        }
        else {
            traverseRight(root->left, result);
        }
        result.push_back(root->data);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> result;
        if(root == NULL) return result;
        result.push_back(root->data);
        traverseLeft(root->left, result);
        traverseLeaf(root->left, result);
        traverseLeaf(root->right, result);
        traverseRight(root->right, result);
        return result;
    }
};