class Node {
    Node* links[26];
    
public:
    bool containsKey(char ch) {
        return links[ch - 'a'];
    }
    
    void put(char ch, Node* node) {
        links[ch - 'a'] = node; 
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

// TC: O(N^2)
// SC: Can't be predicted... {16 * 16 * ..... hypothetical case}
int countDistinctSubstrings(string &s)
{
    Node * root = new Node;
    int n = s.length();
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        Node* temp = root;
        for(int j = i; j < n; j++) {
            if(!temp->containsKey(s[j])) {
                count++;
                temp->put(s[j], new Node());
            }
            temp = temp->get(s[j]);
        }
    }
    return count + 1;
}