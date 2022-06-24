struct Node {
    Node* links[26];
    bool isTerminal = false;
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    
    // returns the reference node of a character in the trie
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    
    bool isEnd() {
        return isTerminal;
    }
    
    void setEnd() {
        isTerminal = true;
    }
};

class Trie {
private: Node* root;
    
public:
    Trie() {
        root = new Node();
    }

public: 
    void insert(string &word) {
        Node* temp = root;
        for(char &ch : word) {
            if(!temp->containsKey(ch)) {
                temp->put(ch, new Node());
            }
            temp = temp->get(ch);
        }
        temp->setEnd();
    }

public:
    bool isCompleteString(string &word) {
        Node* temp = root;
        for(char &ch : word) {
            temp = temp->get(ch);
            if(!temp->isEnd()) return false;
        }
        return true;
    }
    
};

// TC: O(N * K + N * K) K : avg length of each string
string completeString(int n, vector<string> &a){
    // Write your code here.
//     sort(a.begin(), a.end());
    Trie trie;
    for(auto &str : a) {
        trie.insert(str);
    }
    
    string ans = "";
    for(auto &str : a) {
        if(trie.isCompleteString(str)) {
            if(str.length() > ans.length()) {
                ans = str;
            }
            else if(str.length() == ans.length() && str < ans) {
                ans = str;
            }
        }
    }
    return ans != "" ? ans : "None";
}