// Inserts, Searches in O(word length) time
class Trie;
class Node{
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;
    
    friend class Trie;
    
public:
    Node(char d) {
        data = d;
        isTerminal = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
       root = new Node('\0'); 
    }
    
    void insert(string word) {
        Node* temp = root;
        for(char &ch : word) {
            if(temp != NULL && temp->m.count(ch) == 0) {
                Node* n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(char &ch : word) {
            if(temp->m.count(ch) == 0) return false;
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char &ch : prefix) {
            if(temp->m.count(ch) == 0) return false;
            temp = temp->m[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// 24/06/22
#include<bits/stdc++.h>
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
struct Node{
    Node* links[26];
    bool isTerminal = false;
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    void setEnd() {
        isTerminal = true;
    }
    
    bool isEnd() {
        return isTerminal;
    }
    

};

class Trie {
    Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* temp = root;
        for(char &ch : word) {
            if(!temp->containsKey(ch)) {
                temp->put(ch, new Node());
            }
            // moves to the reference node
            temp = temp->get(ch);
        }
        temp->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* temp = root;
        for(char &ch : word) {
            if(!temp->containsKey(ch)) return false;
            temp = temp->get(ch);
        }
        return temp->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char &ch : prefix) {
            if(!temp->containsKey(ch)) return false;
            temp = temp->get(ch);
        }
        return true;
    }
};