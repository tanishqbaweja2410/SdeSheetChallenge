struct Node {
    
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    
    void increaseEnd() {
        cntEndWith++;
    }
    
    void increasePrefix() {
        cntPrefix++;
    }  
    
    void deleteEnd() {
        cntEndWith--;
    }
    
    void reducePrefix() {
        cntPrefix--;
    }
    
    int getEnd() {
        return cntEndWith;
    }
    
    int getPrefix() {
        return cntPrefix;
    }
    
    
    
    
};
class Trie{
private:
    Node* root;
    
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* temp = root;
        for(char &ch : word) {
            if(!temp->containsKey(ch)) {
                temp->put(ch, new Node());
            }
            temp = temp->get(ch);
            temp->increasePrefix();
        }
        temp->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* temp = root;
        for(char &ch : word) {
            if(!temp->containsKey(ch)) return 0;
            temp = temp->get(ch);
        }
        return temp->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* temp = root;
        for(char &ch : word) {
            if(!temp->containsKey(ch)) return 0;
            temp = temp->get(ch);
        }
        return temp->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* temp = root;
        for(char &ch : word) {
            if(!temp->containsKey(ch)) return;
            temp = temp->get(ch);
            temp->reducePrefix();
        }
        temp->deleteEnd();
    }
};

