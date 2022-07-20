class Node{
public:
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void insertKey(char ch,Node *node){
        links[ch-'a'] = node;
    }
    
    Node* getNext(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isSetEnd(){
        return flag == true;
    }
};

class Trie{
private:
    Node *root;
public: 
    // constructor to initialize trie -> root of the trie
    Trie(){
        root = new Node();
    }
    
    void insert(string &word){
        Node *node = root;
        
        int n = word.size();
        for(int i=0;i<n;++i){
            if(!node->containsKey(word[i])){
                node->insertKey(word[i],new Node());
            }
            node = node->getNext(word[i]);
        }
        node->setEnd();
    }
    
    bool areAllPrefExists(string &word){
        Node *node = root;
        
        int n = word.size();
        for(int i=0;i<n;++i){
            if(!node->containsKey(word[i]))return false;
            else{
                node = node->getNext(word[i]);
                if(!node->isSetEnd())return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;    // object of trie class
        
        int n = words.size();
        for(int i=0;i<n;++i){
            trie.insert(words[i]);
        }

        string longest = "";
        for(int i=0;i<n;++i){
            if(!trie.areAllPrefExists(words[i]))continue;

            if(longest.size()<words[i].size()){
                longest = words[i];
            }
            else if(longest.size()==words[i].size() && longest>words[i]){    // check for lexicographically smallest 
                longest = words[i];
            }
        }
        return longest;
    }
};