class Node{
public:
    Node *links[26];
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
};

class Trie {
private:
    Node *root;
    
public:
    // initialize Trie -> root of Trie
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;  // node to iterate in trie
        int n = word.size();
        for(int i=0;i<n;++i){
            if(!node->containsKey(word[i])){
                node->insertKey(word[i],new Node());
            }
            node = node->getNext(word[i]);
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node *node = root;  // node to iterate in trie
        int n = word.size();
        for(int i=0;i<n;++i){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->getNext(word[i]);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;  // node to iterate in trie
        int n = prefix.size();
        for(int i=0;i<n;++i){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->getNext(prefix[i]);
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