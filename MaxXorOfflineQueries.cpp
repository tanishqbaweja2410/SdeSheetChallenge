struct Node {
    Node* links[2];

    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }
    
    Node* get(int bit) {
        return links[bit];
    }
    
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        Node* temp = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!temp->containsKey(bit)) {
                temp->put(bit, new Node());
            }
            temp = temp->get(bit);
        }
    }
    
    int getMaxXor(int num) {
        int maxXor = 0;
        Node* temp = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(temp->containsKey(1 - bit)) {
                maxXor = maxXor | (1 << i);
                temp = temp->get(1 - bit);
            }
            else {
                temp = temp->get(bit);
            }
        }
        return maxXor;
    }
    
};
// TC: O(Q * 32) + (N * 32)
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int,int>>> offlineQueries;
        int q = queries.size();
        for(int i = 0; i < q; i++) {
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }
        // sort(offlineQueries.begin(), offlineQueries.end(), [](pair<int, pair<int,int>> &A, pair<int, pair<int,int>> &B) {
        //    return A.first <= B.first; 
        // });
        sort(offlineQueries.begin(), offlineQueries.end());
        int ind = 0;
        int n = nums.size();
        vector<int> result(q);
        Trie trie;
        for(auto &it : offlineQueries) {
            int num = it.second.first;
            int bound = it.first;
            int queryInd = it.second.second;
            while(ind < n) {
                if(nums[ind] <= bound) {
                    trie.insert(nums[ind]);
                    ind++;
                }
                else break;
            }
            
            if(ind == 0) result[queryInd] = -1;
            else result[queryInd] = trie.getMaxXor(num);
        }
        return result;
    }
};