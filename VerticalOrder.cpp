// Codestudio Solution
// TC: O(N * logN * logN)
// SC: O(N) for storing all nodes in map + O(N) for storing in queue{should be 3*N more apt but N if considering only nodes}
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    map<int, map<int, vector<int>>> m;
    // level order traversal
    queue<pair<TreeNode<int>*, pair<int,int>>> q;
    int horizontalDistance = 0;
    int level = 0;
    q.push({root, {horizontalDistance, level}});

    while(!q.empty()) {
        auto current = q.front();
        q.pop();

        // info about the popped node
        TreeNode<int>* currentNode = current.first;
        int currentHorizontalDistance = current.second.first;
        int currentLevel = current.second.second;

        // insert in the map
        m[currentHorizontalDistance][currentLevel].push_back(currentNode->data);

        // check whether left or right exists or not 
        // and accordingly add to the queue
        if(currentNode->left) {
            q.push({currentNode->left, {currentHorizontalDistance - 1, currentLevel + 1}});
        }
        if(currentNode->right) {
            q.push({currentNode->right, {currentHorizontalDistance + 1, currentLevel + 1}});
        }
    }


    for(auto &it : m) {
        for(auto &x : it.second) {
            vector<int> s = x.second;
            ans.insert(ans.end(), s.begin(), s.end());
        }
    }

    return ans;

}

// Leetcode 
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
// Leetcode Solution
// TC: O(N * logN * logN * logN)
// SC: O(N) for storing all nodes in map + O(N) for storing in queue{should be 3*N more apt but N if considering only nodes}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> m;
        // level order traversal
        queue<pair<TreeNode*, pair<int,int>>> q;
        int horizontalDistance = 0;
        int level = 0;
        q.push({root, {horizontalDistance, level}});
        
        while(!q.empty()) {
            auto current = q.front();
            q.pop();
            
            // info about the popped node
            TreeNode* currentNode = current.first;
            int currentHorizontalDistance = current.second.first;
            int currentLevel = current.second.second;
            
            // insert in the map
            m[currentHorizontalDistance][currentLevel].insert(currentNode->val);
            
            // check whether left or right exists or not 
            // and accordingly add to the queue
            if(currentNode->left) {
                q.push({currentNode->left, {currentHorizontalDistance - 1, currentLevel + 1}});
            }
            if(currentNode->right) {
                q.push({currentNode->right, {currentHorizontalDistance + 1, currentLevel + 1}});
            }
        }
        
        
        for(auto &it : m) {
            vector<int> temp;
            for(auto &x : it.second) {
                multiset<int> s = x.second;
                temp.insert(temp.end(), s.begin(), s.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};