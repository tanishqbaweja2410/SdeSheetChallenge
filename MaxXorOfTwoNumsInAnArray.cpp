// TC: O(N * 32) + (N * 32)
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
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &it : nums) {
            trie.insert(it);
        }
        
        int maxi = 0;
        for(auto &it : nums) {
            maxi = max(maxi, trie.getMaxXor(it));
        }
        return maxi;
    }
};